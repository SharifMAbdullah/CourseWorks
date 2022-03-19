package Introduction;

public class Rocket_management extends CreateAccount {
    public Rocket_management(String user_name,String user_num, String user_pin){
        super(user_name, user_num, user_pin);
    }

    public void cash_out(double amount, String pin){
        set_cashout_charge(18);

        if(amount > 250000)
            System.out.println("Valid amount of withdrawing money exceeded!");
        else super.cash_out(amount,pin);
    }
}
