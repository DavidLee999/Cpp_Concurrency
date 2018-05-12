struct card_inserced
{
    std::string account;
};

class atm
{
    messaging::receiver incoming;
    messaging::sender bank;
    messaging::sender interface_hardware;

    void (atm::*state)();

    std::string account;
    std::string pin;

    void waiting_for_card()
    {
        interface_hardware.send(display_enter_card());
        incoming.wait()
            .handle<card_inserced>(
                    [&](card_inserced const& msg)
                    {
                        account = msg.account();
                        pin = "";
                        interface_hardware.send(display_enter_pin());
                        state = &atm.getting_pin;
                    });
    }

    void getting_pin()
    {
        incoming.wait()
            .handle<digit_pressed>(
                [&](digit_pressed const& msg)
                {
                    unsigned const pin_length = 4;
                    pin += msg.digit;
                    if(pin.length() == pin_length)
                    {
                        bank.send(verify_pin(account, pin, incoming));
                        state = &atm::verifying_pin;
                    }
                })
            .handle<clear_last_pressed>(
                [&](clear_last_pressed const& msg)
                {
                    if (!pin.empty())
                    {
                        pin.reseize(pin.length() - 1);
                    }
                })
            .handle<cancel_pressed>(
                    [&](cancel_pressed const& msg)
                    {
                        state = &atm::done_processing;
                    });
    }

    public:
    void run()
    {
        state = &atm::waiting_for_card;
        try
        {
            for(;;)
            {
                (this->*state)();
            }
        }

        catch(messaging::close_queue const&)
        {
        }
    }
};