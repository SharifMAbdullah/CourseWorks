package Introduction;

public class CreateAccount {

    public void startBanking() {
//        Banking Abdullah = new Banking("SMA", "01521561758");
//        Abdullah.cash_out(500, 1234);




        String fahad_pin="\0";
        String adeb_pin="2345";

        Banking fahad= new Banking("Fahad","01732434234");
        Banking Abdullah=new Banking("Adeb","01231324545",adeb_pin);

        System.out.println("Initial balance of fahad: "+fahad.toString());
        System.out.println("Initial balance of Adeb: "+Abdullah.toString());

        fahad.add_money(10000);
        Abdullah.add_money(1000);

        Abdullah.cash_out(235,adeb_pin);
        fahad.cash_out(500,fahad_pin);

        fahad_pin=fahad.pin_update(fahad_pin,"3432")?"3432":fahad_pin;


        Abdullah.cash_out(235,adeb_pin);
        fahad.cash_out(1000,fahad_pin);
        fahad.cash_out(1000,adeb_pin);

        fahad_pin = fahad.pin_update(fahad_pin,"2678")?"2678":fahad_pin;

    }
}
