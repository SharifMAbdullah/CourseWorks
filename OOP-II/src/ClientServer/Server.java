package ClientServer;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private Socket socket;
    private ServerSocket serverSocket;

    private DataInputStream dataInputStream;
    private DataOutputStream dataOutputStream;

    public Server(int port) {
        try {
            this.serverSocket = new ServerSocket(port);
            this.socket = this.serverSocket.accept();
            System.out.println("Connection has been established!");

            this.dataInputStream = new DataInputStream(new BufferedInputStream(socket.getInputStream())); // byte stream
            this.dataOutputStream = new DataOutputStream(socket.getOutputStream()); // Buffer korle problem hbe?

            String line = "";
            while(!line.equals("Abir")){
                line = this.dataInputStream.readUTF();
                System.out.println("Client sends: "+line);
                this.dataOutputStream.writeUTF("Server says: "+line.toUpperCase());
            }

            this.dataOutputStream.close();
            this.dataInputStream.close();
            this.socket.close();
            this.serverSocket.close();

            System.out.println("Connection Closed");
        }catch(IOException e){e.printStackTrace();}
    }

    public static void main(String[] args){
        Server server = new Server(43021);
    }
}
