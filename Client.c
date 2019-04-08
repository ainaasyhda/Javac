import java.util.Scanner;



import java.io.*;



import java.net.*;



import java.net.Socket.*;





class TCPClient {



 public static void main(String argv[]) throws IOException {



  String sentence;



  String modifiedSentence;

 

  Scanner n = new Scanner(System.in);



  System.out.print("Do you want to ping or send message ? ( 1 - Ping , 2 - Message) \n");



    int input = n.nextInt();

 

 if(input == 1)

{

    

    String ipAddress = "192.168.47.128"; 



    InetAddress geek = InetAddress.getByName(ipAddress); 



    System.out.println("Sending Ping Request to " + ipAddress); 



    if (geek.isReachable(5000)) 



      System.out.println("Host is reachable"); 



    else



      System.out.println("Sorry ! We can't reach to this host"); 



}







else

{



while(true)

{

BufferedReader inFromUser = new BufferedReader(new 

InputStreamReader(System.in));



  

  Socket clientSocket = new Socket("192.168.47.129", 22000);



DataOutputStream outToServer = new 

DataOutputStream(clientSocket.getOutputStream());



  BufferedReader inFromServer = new BufferedReader(new 

InputStreamReader(clientSocket.getInputStream()));





     sentence = inFromUser.readLine();

   

     outToServer.writeBytes(sentence);





  modifiedSentence = inFromServer.readLine();



  System.out.println("FROM SERVER: " + modifiedSentence);





  clientSocket.close();

}

}

}

}
