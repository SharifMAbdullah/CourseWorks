package ClientServer;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {
    private Socket socket;
    private DataInputStream socketInputStream;
    private DataOutputStream socketOutputStream;
    private DataInputStream consoleInputStream;

    Client(String server_ip_addr, int server_port){
        try {
            this.socket = new Socket(server_ip_addr, server_port);
            this.socketInputStream = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            this.socketOutputStream = new DataOutputStream(this.socket.getOutputStream());

            this.consoleInputStream = new DataInputStream(System.in);

            String line = "";
            while(!line.equals("Abir")){
                line = this.consoleInputStream.readLine();
                this.socketOutputStream.writeUTF(line);
                System.out.println(this.socketInputStream.readUTF());
            }

            this.socket.close();
            this.socketInputStream.close();
            this.socketOutputStream.close();
            this.consoleInputStream.close();
        }catch(IOException e){e.printStackTrace();}
    }

    public static void main(String[] args) {
        Client client = new Client("127.0.0.1", 43021);
    }
}
