package Introduction;
import java.lang.String;

public class CreateAccount {

    private String account_holder_name;
    private String account_phone_number;
    private double balance = 10000;
    private double cash_out_charge;
    private String pin;

    public CreateAccount(String name, String account_phone_number, String pin){
        this.account_holder_name=name;
        this.account_phone_number=account_phone_number;
        this.pin=pin;
    }

    public CreateAccount(String name, String account_phone_number){
        this.account_holder_name=name;
        this.account_phone_number=account_phone_number;
        this.pin="\0";
    }


    public boolean pin_update(String old_pin, String new_pin) {

        if (this.pin == "\0") {
            this.pin = new_pin;
            System.out.println("New pin initialized! ");
            return true;
        }
        else if (old_pin == this.pin) {
            this.pin = new_pin;
            System.out.println("Pin updated! ");
            return true;
        }
        else {
            System.out.println("Old pin doesn't match ");
            return false;
        }
    }

    public void send_money(double amount, String security_pin){
        System.out.println("\nSEND MONEY: ");

        if (security_pin != this.pin) {
            System.out.println("Wrong pin entered, failed to send money!");
        }

            else{
                if(amount > 25000 || amount > balance)
                System.out.println("Send Money limitation exceeded, failed to Send Money!");

                else  if (amount > 500) {
                    this.balance -= (amount + 5);
                    System.out.println("  Send Money: " + amount);
                    System.out.println( +(amount - 5) + "/-" + " taka (including vat) sent successfully.");
                    }

                    else {
                        this.balance -= amount;
                        System.out.println( +amount + "/-" + " taka sent successfully.");
                    }

                }
            System.out.println("Current Balance: " + balance);
        }



    public void add_money(double amount){
        this.balance += amount;
        System.out.println("Add money: " + amount + " "+ account_holder_name);
    }

    public void cash_out(double amount,String pin){

        if(pin!=this.pin){
            System.out.println("Pin doesn't match or is not updated!");}

        else if(pin==this.pin && pin=="\0"){
            System.out.println("Pin not initialized");
        }
        else{
            if (balance >= amount) {
                balance -= amount;
                System.out.println("Cash out: " + amount + account_holder_name);
            }
            else {
                System.out.println("Failed to cash out due to balance limit");
            }
        }
    }

    public String getAccount_holder_name(){
        return this.account_holder_name;
    }

    protected String getAccount_phone_number(){
        return this.account_phone_number;
    }

    public double getBalance(){
        return this.balance;
    }

    public void set_cashout_charge(double charge){
        this.cash_out_charge = charge;
    }
        
}


