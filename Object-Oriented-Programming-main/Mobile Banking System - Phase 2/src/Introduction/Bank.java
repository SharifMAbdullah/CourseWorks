package Introduction;

public class Bank {

    public void startBanking() {

                Bkash_management Abdullah = new Bkash_management("Abdullah", "01521561759", "2593");
                Rocket_management Fahad = new Rocket_management("Fahad", "01333484399", null);
                Nagad_management Sampad = new Nagad_management("Sampad", "016134647916", "1234");


                System.out.println("User info and relevant systems while using Bkash\n");
                Abdullah.add_money(2500);
            Abdullah.send_money(1200, "2593");
            Abdullah.cash_out(1000, "2593");
            Abdullah.pin_update("2593", "1165");
            Abdullah.send_money(900,"1165");
                System.out.println(Abdullah);


                System.out.println("User info and relevant systems while using Rocket \n");
                Fahad.add_money(10000);
            Fahad.send_money(5000,"3423");
            Fahad.cash_out(6000, "1254");
            Fahad.pin_update("3423", "1254");
            Fahad.send_money(1500,"1254");
                System.out.println(Fahad);


                System.out.println("User info and relevant systems while using Nagad");
                Sampad.add_money(2000);
        Sampad.cash_out(300,"1234");
        Sampad.add_money(5000);
        Sampad.cash_out(2000,"3254");
        Sampad.send_money(1000, null);
        Sampad.add_money(40000);

                System.out.println(Sampad);

    }
}
