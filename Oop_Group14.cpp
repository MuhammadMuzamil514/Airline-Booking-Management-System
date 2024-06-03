#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int firstClassSeats = 1;
int economyClassSeats = 2;
int businessClassSeats = 3;

class Login{
    protected:
        string username;
        string password;

    public:
        Login(){
            username="";
            password="";
        }

        void setUsername(string un){
            username=un;
        }

        void setPassword(string np){
            password=np;
        }

        string getUsername(){
            return username;
        }

        string getPassword(){
            return password;
        }

        void createAccount(){
            string usnm;
            string pswrd;
            cout<<"\t\t\tEnter new username: ";
            cin>>usnm;
            cout<<"\t\t\tEnter new password: ";
            cin>>pswrd;

            ofstream onFile("logins.txt",ios::app);
            if(onFile.is_open()){
                onFile<<usnm<<endl;
                onFile<<pswrd<<endl;
                onFile.close();
            }
            else{
                cout<<"\t\t\tUnable to open file for writing."<<endl;
            }
        }

        bool login(){
            string chkusnm;
            string chkpswrd;
            cout<<"\t\t\tEnter your username: ";
            cin>>chkusnm;
            cout<<"\t\t\tEnter your password: ";
            cin>>chkpswrd;

            ifstream inFile("logins.txt");
            string storedUsername,storedPassword;
            bool found =false;

            if(inFile.is_open()){
                while(inFile>>storedUsername>>storedPassword){
                    if(storedUsername==chkusnm&&storedPassword==chkpswrd){
                        found=true;
                        break;
                    }
                }
                inFile.close();

                if (found){
                    cout<<"\t\t\tLogin Successful!"<<endl;
                    return true;
                } else{
                    cout<<"\t\t\tInvalid username or password."<<endl;
                    return false;
                }
            } else{
                cout<<"\t\t\tUnable to open file for reading."<<endl;
                return false;
            }
        }
};
class Airplane{
    protected:
        string planeID;
        string Planename;
        string time;
        string location;
        int Price;
        string seatclass;
        int TotalSeats;

    public:
        Airplane(){
        	
            planeID="";
            Planename="";
            time="";
            location="";
            Price=0;
            seatclass="";
            
        } 

        Airplane(string id,string n,string t,string loc){
            planeID=id;
            Planename=n;
            time=t;
            location=loc;
            Price=0;
            seatclass="";
        }

        void setflights(int firspric,int buspri,int ecpr){
            
            int setclass;
            
            cout<<"\t\t\tChoose class: "<<endl;
            cout<<"\n\t\t\t1. Economy Class"<<endl;
            
            cout<<"\t\t\t   Price: "<<ecpr<<" PKR"<<endl;
            cout<<"\t\t\t2. First Class"<<endl;
            
            cout<<"\t\t\t   Price: "<<firspric<<" PKR"<<endl;
            cout<<"\t\t\t3. Business Class"<<endl;
            
            cout<<"\t\t\t   Price: "<<buspri<<" PKR"<<endl;
            cout<<"\t\t\tEnter your choice: ";
            cin>>setclass;
            
            if(setclass==1) {
                Price=ecpr;
                seatclass="Economy";
            }
            else if(setclass==2){
                Price=firspric;
                seatclass="First";
            }
            else if(setclass==3){
                Price=buspri;
                seatclass="Business";
            }
            else{
                cout<<"\t\t\tInvalid class choice."<<endl;
            }
            
            int numberOfSeats;
            cout<<"\t\t\tEnter the total number of Seats: ";
            cin>>numberOfSeats;
        
            TotalSeats=numberOfSeats;    
            
        }
        
        string getPlaneID(){
            return planeID;
        }
        
        string getPlanename(){
            return Planename;
        }
        
        string getTime(){
            return time;
        }
        
        string getLocation(){
            return location;
        }
        
        int getPrice(){
            return Price;
        }
        
        int getTotalSeats(){
            return TotalSeats;
        }

        string getseatclass() {
            return seatclass;
        }
        
        bool checkSeatAvailability() {
            int bookedSeats = 0;
            string line;
            ifstream inFile("ticketFile.txt");

            if (inFile.is_open()) {
                while (getline(inFile, line)) {
            if (line.find("Plane ID: " + planeID) != string::npos) {
                while (getline(inFile, line) && !line.empty()) {
                    if (line.find("Seat Class: " + seatclass) != string::npos) {
                        size_t pos = line.find("Total Seats: ");
                        if (pos != string::npos) {
                            // Extract the number after "Total Seats: "
                            stringstream ss(line.substr(pos + 13));
                            int seats;
                            ss >> seats;
                            bookedSeats += seats;
                        }
                    }
                }
            }
        }
        inFile.close();
    }

   
        if (seatclass == "Economy") {
            return (bookedSeats + TotalSeats) <= economyClassSeats;
        } else if (seatclass == "First") {
            return (bookedSeats + TotalSeats) <= firstClassSeats;
        } else if (seatclass == "Business") {
            return (bookedSeats + TotalSeats) <= businessClassSeats;
        } else {
        return false;
    }
}

};
class Passenger {
    protected:
        int FlightID;
        string Firstname;
        string Lastname;
        string email;
        string phoneNumber;
        string passportNumber;
        double luggageSize;
        int extrapay;

    public:
        Passenger() {
            Firstname="";
            Lastname="";
            email="";
            phoneNumber="";
            passportNumber="";
            luggageSize=0;
            extrapay=0;
            FlightID=0;
        }  

        void setValue() {
            cout<<"\t\t\tEnter Passenger Detail: "<<endl;
            cout<<"\n\t\t\tEnter Passenger First Name: ";
            cin>>Firstname;
            cout<<"\t\t\tEnter Passenger Last Name: ";
            cin>>Lastname;
            cout<<"\t\t\tEnter Email: ";
            cin>>email;
            cout<<"\t\t\tEnter Phone Number: ";
            cin>>phoneNumber;
            cout<<"\t\t\tEnter Passport Number: ";
            cin>>passportNumber;
            cout<<"\t\t\tEnter Luggage Size (Will be less than 32kg otherwise extra 500PK pays): ";
            cin>>luggageSize;
            if (luggageSize>32){
                extrapay=500; 
                cout<<"\t\t\tExtra added due to over Luggage: "<<endl;
            } else {
                extrapay=0;
            }
        }
        
        int getFlightID(){
            return FlightID;
        }
        
        string getFirstname() {
            return Firstname;
        }
        
        string getLastname() {
            return Lastname;
        }

        string getemail() {
            return email;
        }

        string getphoneNumber() {
            return phoneNumber;
        }

        string getpassportNumber() {
            return passportNumber;
        }
        
        double getluggageSize(){
            return luggageSize;
        }
        
        int getextrapay(){
            return extrapay;
        }
};
class Ticket :public Airplane,public Passenger {
	public:
		Ticket(Airplane& flight):Airplane(flight),Passenger(){
	}
     int getNextFlightID(){
        int lastID=0;
        ifstream inFile("lastFlightID.txt");
        if(inFile.is_open()) {
            inFile>>lastID;
            inFile.close();
        }
        lastID++;
        ofstream outFile("lastFlightID.txt");
        if(outFile.is_open()){
            outFile<<lastID;
            outFile.close();
        }
        return lastID;
    }
    
    void bookTicket(){
    ofstream outFile("ticketFile.txt",ios::app); 
    
    FlightID=getNextFlightID();
    
    if(outFile.is_open()){
        
        outFile<<"\nPassport Number: "<<passportNumber<<endl;
        outFile<<"\t\t\tFlight ID: "<<FlightID<<endl;
        outFile<<"\t\t\tFirst Name: "<<Firstname<<endl;
        outFile<<"\t\t\tLast Name: "<<Lastname<<endl;
        outFile<<"\t\t\tEmail: "<<email<<endl;
        outFile<<"\t\t\tPhone Number: "<<phoneNumber<<endl;
        outFile<<"\t\t\tPlane ID: "<<planeID<<endl;
        outFile<<"\t\t\tPlane Name: "<<Planename<<endl;
        outFile<<"\t\t\tTime: "<<time<<endl;
        outFile<<"\t\t\tLocation: "<<location<<endl;
        outFile<<"\t\t\tPrice: "<<(Price *TotalSeats)+extrapay<<" PKR"<<endl;
        outFile<<"\t\t\tSeat Class: "<<seatclass<<endl;
        outFile<<"\t\t\tTotal Seats: "<<TotalSeats<<endl;
        outFile<<"\t\t\tLuggage Size: "<<luggageSize<<" kg"<<endl;

        cout<<"\t\t\tTicket booked successfully!"<<endl;
        outFile.close();
    } else{
        cout<<"\t\t\tUnable to open file for writing."<<endl;
    }
}
void ViewTicket(){
	
    string passport;
    cout<<"\t\t\tEnter your passport number: ";
    cin>>passport;

    ifstream inFile("ticketFile.txt");
    if(inFile.is_open()){
        string line;
        bool found=false;
        while(getline(inFile,line)){
            if(line.find("Passport Number: " +passport)!=string::npos){
                found=true;
                cout<<"\t\t\tTicket Found!\n\n";
                // Print ticket details until a separator line is reached
                while(getline(inFile,line)&&!line.empty() ){
                    cout<<"\t\t\t"<<line<<endl;
                }
                break;
            }
        }
        inFile.close();

        if(!found){
            cout<<"\t\t\tTicket not found for passport number: "<<passport<<endl;
        }
    } else{
        cout<<"\t\t\tUnable to open file for reading."<<endl;
    }
}
void cancelTicket(){
    string passportNumber;
    cout<<"\t\t\tEnter your passport number: ";
    cin>>passportNumber;
    
    ifstream inFile("ticketFile.txt");
    ofstream tempFile("tempTicketFile.txt");
    if (inFile.is_open()&&tempFile.is_open()){
        string line;
        bool found=false;
        while (getline(inFile,line)) {
            if (line.find("Passport Number: "+passportNumber)!=string::npos){
                // Skip ticket information for the provided passport number
                found =true;
                while(getline(inFile, line)&&!line.empty()){
                    // Skip lines until an empty line is encountered
                }
            } else {
                // Write other ticket information to the temporary file
                tempFile<<line<<endl;
            }
        }
        inFile.close();
        tempFile.close();
        
        if (found){
            // Delete the original file
            remove("ticketFile.txt");
            // Rename the temporary file to the original file name
            rename("tempTicketFile.txt","ticketFile.txt");
            cout<<"\t\t\tTicket canceled successfully!"<<endl;
        } else{
            cout<<"\t\t\tTicket not found for passport number: "<<passportNumber<<endl;
        }
    } else{
        cout<<"\t\t\tUnable to open file for reading or writing."<<endl;
    }
}
void adminlogin() {
    string username,password;
    cout<<"\t\t\tEnter username: ";
    cin>>username;
    cout<<"\t\t\tEnter password: ";
    cin>>password;

    if(username=="admin"&&password=="admin") {
        cout<<"Admin login successful!"<<endl;

        // Display list of planes
        cout<<"\nAvailable Planes:\n";
        cout<<"\t\t\t1. Plane ID: 123, Name: ATR 42\n";
        cout<<"\t\t\t2. Plane ID: 456, Name: ATR 72\n";
        cout<<"\t\t\t3. Plane ID: 789, Name: Airbus A320\n";
        cout<<"\t\t\t4. Plane ID: 101, Name: Boeing 777\n";
        cout<<"\t\t\t5. Plane ID: 112, Name: Airbus A320\n";
        cout<<"\t\t\t6. Plane ID: 131, Name: Boeing 787 Dreamliner\n";

        string planeID;
        cout<<"\nEnter the plane ID to view bookings: ";
        cin>>planeID;

        // Read and display booking numbers from the file for the selected plane
        ifstream inFile("ticketFile.txt");
        if(inFile.is_open()) {
            string line;
            bool found=false;
            int totalBookings=0;
            int totalSeatsBooked=0;
            int economySeatsBooked=0;
            int businessSeatsBooked=0;
            int firstSeatsBooked=0;

            while(getline(inFile,line)){
                if(line.find("Plane ID: " +planeID)!=string::npos) {
                    found =true;
                    totalBookings++;

                    // Track the class and number of seats booked
                    string seatClass;
                    int seats=0;

                    while(getline(inFile, line)&&!line.empty()){
                        if(line.find("Seat Class: ")!=string::npos){
                            seatClass=line.substr(line.find(":")+2);
                        }
                        if(line.find("Total Seats: ")!=string::npos) {
                            stringstream ss(line);
                            string temp;
                            ss>>temp>>temp>>seats; // Extract the number of seats
                        }
                    }

                    // Update seat counts based on class
                    if(seatClass=="Economy") {
                        economySeatsBooked+=seats;
                    } else if(seatClass=="Business") {
                        businessSeatsBooked+=seats;
                    } else if(seatClass=="First") {
                        firstSeatsBooked+=seats;
                    }
                    totalSeatsBooked+=seats;
                }
            }
            inFile.close();

            if(found){
                cout<<"\t\t\tTotal Bookings for Plane ID: "<<planeID<<" is "<<totalBookings<<endl;
                cout<<"\t\t\tTotal Seats Booked: "<<totalSeatsBooked<<endl;
                cout<<"\t\t\tEconomy Class Seats Booked: "<<economySeatsBooked<<endl;
                cout<<"\t\t\tBusiness Class Seats Booked: "<<businessSeatsBooked<<endl;
                cout<<"\t\t\tFirst Class Seats Booked: "<<firstSeatsBooked<<endl;
            } else{
                cout<<"\t\t\tNo bookings found for Plane ID: "<<planeID<<endl;
            }
        } else{
            cout<<"\t\t\tUnable to open file for reading."<<endl;
        }
    } else{
        cout<<"\t\t\tInvalid admin credentials!"<<endl;
    }
}
};
int main(){
    Login obj1;

    int choice;
    cout<<"\t\t\tCreate New Account or Login"<<endl;
    cout<<"\n\t\t\t1: Create new account."<<endl;
    cout<<"\t\t\t2: Login."<<endl;
    cin>>choice;
    
    system("cls");

    if (choice==1){
        cout<<"\t\t\tCreate New Account"<<endl;
        obj1.createAccount();
        system("cls");
        cout<<"\t\t\tLogin"<<endl;
        if(obj1.login()==false) {
            return 0;
        }
    } else if(choice==2) {
        cout<<"\t\t\tLogin"<<endl;
        if (obj1.login()==false){
            return 0;
        }
    } else {
        cout<<"\t\t\tInvalid choice."<<endl;
        return 0;
    }
    
    system("cls");
    Airplane plane1("123","ATR 42","2024-06-05 07:00am","Karachi to Islamabad");
    Airplane plane2("456","ATR 72","2024-06-05 12:00pm","Lahore to Peshawar");
    Airplane plane3("789","Airbus A320","2024-06-05 08:00pm","Islamabad to Quetta");
    Airplane plane4("101","Boeing 777","2024-06-05 07:00am","Pakistan to Dubai");
    Airplane plane5("112","Airbus A320","2024-06-05 12:00pm","Pakistan to Toronto");
    Airplane plane6("131","Boeing 787 Dreamliner","2024-06-05 08:00pm","Pakistan to London");
    
    int choice2;
    
    do{
        int choice1;
        Airplane selectedFlight;
        cout<<"\t\t\tWelcome to Air Management system."<<endl;
        
        cout<<"\n\t\t\t1. Book Ticket"<<endl;
        cout<<"\t\t\t2. View Tickets"<<endl;
        cout<<"\t\t\t3. Cancel Ticket"<<endl;
        cout<<"\t\t\t4. Admin Login"<<endl;
        cout<<"\t\t\t5. Exit"<<endl;
        
        cout<<"\t\t\tEnter your choice: ";
        cin>>choice1;
        
        Passenger obj2;
        system("cls");
        
        switch (choice1){
            case 1: {
                cout<<"\t\t\tTicket Booking..."<<endl;
                
                cout<<"\n\t\t\t1. Domestic flights (within Pakistan)"<<endl;
                
                cout<<"\t\t\t2. International flights (outside Pakistan)"<<endl;
                
                cout<<"\t\t\tEnter your choice: ";
                cin>>choice2;
                
                system("cls");
                
                if(choice2==1){
                    int choice3;
                    cout<<"\t\t\tTicket Booking..."<<endl;
                    cout<<"\t\t\tDomestic flights (within Pakistan)"<<endl;
                    
                    cout<<"\n\t\t\t1. From Karachi to Islamabad."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 07:00am"<<endl;
                    
                    cout<<"\n\t\t\t2. From Lahore to Peshawar."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 12:00pm"<<endl;
                    
                    cout<<"\n\t\t\t3. From Islamabad to Quetta."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 08:00pm"<<endl;
                    cout<<"\t\t\tEnter your choice: ";
                    cin>>choice3;
                    
                    system("cls");
                    
                    if(choice3==1) {
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane1.setflights(140000,70000,28000);
                        selectedFlight = plane1; 
                        
                    } else if(choice3==2) {
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane2.setflights(120000,60000,25000);
                        selectedFlight=plane2; 
                    } else if(choice3==3) {
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane3.setflights(130000,65000,26000);
                        selectedFlight=plane3;
                    } else {
                        cout<<"\t\t\tInvalid choice."<<endl;
                        return 0;
                    }
                    
                } else if(choice2==2) {
                    int choice4;
                    cout<<"\t\t\tTicket Booking..."<<endl;
                    cout<<"\t\t\tInternational flights (outside Pakistan)"<<endl;
                    
                    cout<<"\n\t\t\t1. From Karachi to Dubai."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 07:00am"<<endl;
                    
                    cout<<"\n\t\t\t2. From Lahore to Toronto."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 12:00pm"<<endl;
                    
                    cout<<"\n\t\t\t3. From Islamabad to London."<<endl;
                    cout<<"\t\t\t     Time: 2024-06-05 08:00pm"<<endl;
                    cout<<"\t\t\tEnter your choice: ";
                    cin>>choice4;
                    
                    system("cls");
                    
                    if (choice4==1){
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane4.setflights(250000,120000,50000);
                        selectedFlight=plane4;
                    } else if (choice4 ==2) {
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane5.setflights(900000,450000,200000);
                        selectedFlight=plane5; 
                    } else if(choice4 ==3){
                        cout<<"\t\t\tTicket Booking..."<<endl;
                        plane6.setflights(900000,450000,190000);
                        selectedFlight=plane6;
                    } else {
                        cout<<"\t\t\tInvalid choice."<<endl;
                        return 0;
                    }
                } else{
                    cout<<"\t\t\tInvalid choice."<<endl;
                    return 0;
                }
                
                if(selectedFlight.checkSeatAvailability() == true){
                	Ticket obj3(selectedFlight);
                    system("cls"); 
                    obj3.setValue();
                    cout<<endl;
                    obj3.bookTicket();
				}else{
					cout<<"\t\t\tSeats are not avilibale."<<endl;
				}
                break;
            }
            case 2: {
                cout<<"\n\t\t\tViewing Tickets...\n";
                Ticket obj3(selectedFlight); // Create a temporary Ticket object
                obj3.ViewTicket();
                break;
            }
            case 3:{
                cout<<"\n\t\t\tCanceling Ticket...\n";
                Ticket obj3(selectedFlight); // Create a temporary Ticket object
                obj3.cancelTicket();
                break;
            }
            case 4:{
                cout<<"\n\t\t\tAdmin Login...\n";
                Ticket t4(selectedFlight);
                t4.adminlogin();
                break;
            }
            case 5:{
                cout<<"\n\t\t\tExiting...\n";
                choice2=5; 
                break;
            }
            default:{
                cout<<"\n\t\t\tInvalid choice. Please try again.\n";
                break;
            }
        }
        
        cout<<"\t\t\tPress any key to return to the main menu...";
        cin.ignore();
        cin.get();
        system("cls");
        
    } while(choice2!=5); 

}
