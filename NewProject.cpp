#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//const int MAX_FLIGHTS = 9;
//const int MAX_FIRST = 2;
//const int MAX_ECONOMY = 2;
//const int MAX_BUSINESS = 5;

class Login {
    protected:
        string username;
        string password;

    public:
        Login(){
        	
        	username = "";
			password = "";
			
		}

        void setUsername(string un){
            username = un;
        }

        void setPassword(string np){
            password = np;
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
            cout << "Enter new username: ";
            cin >> usnm;
            cout << "Enter new password: ";
            cin >> pswrd;

            ofstream onFile("logins.txt", ios::app);
            if(onFile.is_open()){
                onFile << usnm << endl;
                onFile << pswrd << endl;
                onFile.close();
            }
            else{
                cout << "Unable to open file for writing." << endl;
            }
        }

        bool login() {
            string chkusnm;
            string chkpswrd;
            cout << "Enter your username: ";
            cin >> chkusnm;
            cout << "Enter your password: ";
            cin >> chkpswrd;

            ifstream inFile("logins.txt");
            string storedUsername, storedPassword;
            bool found = false;

            if (inFile.is_open()) {
                while (inFile >> storedUsername >> storedPassword) {
                    if (storedUsername == chkusnm && storedPassword == chkpswrd) {
                        found = true;
                        break;
                    }
                }
                inFile.close();

                if (found) {
                    cout << "Login Successful!" << endl;
                    return true;
                } else {
                    cout << "Invalid username or password." << endl;
                    return false;
                }
            } else {
                cout << "Unable to open file for reading." << endl;
                return false;
            }
        }
};
class Airplane {
    protected:
        string planeID;
        string Planename;
        string time;
        string location;
        int Price;
        string seatclass;
        int TotalSeats;

    public:
        Airplane() {
        	
            planeID = "";
            Planename = "";
            time = "";
            location = "";
            Price = 0;
            seatclass = "";
            
        } 

        Airplane(string id, string n, string t, string loc){
            planeID = id;
            Planename = n;
            time = t;
            location = loc;
            Price = 0;
            seatclass = "";
        }

        void setclassForDomesticflights(int ecpr, int buspri) {
            int setclass;
            
            cout << "Choose class: " << endl;
            
            cout << "\n1. Economy Class" << endl;
            cout << "   Price: " << ecpr << " PKR" << endl;
            
            cout << "2. Business Class" << endl;
            cout << "   Price: " << buspri << " PKR" << endl;
            
            cout << "Enter your choice: ";
            cin >> setclass;
            
            if (setclass == 1) {
                Price = ecpr;
                seatclass = "Economy";
            }
            else if (setclass == 2) {
                Price = buspri;
                seatclass = "Business";
            }
            else {
                cout << "Invalid class choice." << endl;
            }
            
            int numberOfSeats;
            cout<<"Enter the total number of Seats: ";
            cin>>numberOfSeats;
        
            TotalSeats = numberOfSeats;
        }

        void setclassForInternationalflights(int ecpr, int firspric, int buspri) {
            
            int setclass;
            
            cout << "Choose class: " << endl;
            cout << "\n1. Economy Class" << endl;
            
            cout << "   Price: " << ecpr << " PKR" << endl;
            cout << "2. First Class" << endl;
            
            cout << "   Price: " << firspric << " PKR" << endl;
            cout << "3. Business Class" << endl;
            
            cout << "   Price: " << buspri << " PKR" << endl;
            cout << "Enter your choice: ";
            cin >> setclass;
            
            if (setclass == 1) {
                Price = ecpr;
                seatclass = "Economy";
            }
            else if (setclass == 2) {
                Price = firspric;
                seatclass = "First";
            }
            else if (setclass == 3) {
                Price = buspri;
                seatclass = "Business";
            }
            else {
                cout << "Invalid class choice." << endl;
            }
            
            int numberOfSeats;
            cout<<"Enter the total number of Seats: ";
            cin>>numberOfSeats;
        
            TotalSeats = numberOfSeats;    
            
        }
        
        string getPlaneID() {
            return planeID;
        }
        
        string getPlanename() {
            return Planename;
        }
        
        string getTime() {
            return time;
        }
        
        string getLocation() {
            return location;
        }
        
        int getPrice() {
            return Price;
        }
        
        int getTotalSeats(){
            return TotalSeats;
        }

        string getseatclass() {
            return seatclass;
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
            Firstname = "";
            Lastname = "";
            email = "";
            phoneNumber = "";
            passportNumber = "";
            luggageSize = 0;
            extrapay = 0;
            FlightID = 0;
        }  

        void setValue() {
            cout<<"Enter Passenger Detail: "<<endl;
            cout << "\nEnter Passenger First Name: ";
            cin >> Firstname;
            cout << "Enter Passenger Last Name: ";
            cin >> Lastname;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Phone Number: ";
            cin >> phoneNumber;
            cout << "Enter Passport Number: ";
            cin >> passportNumber;
            cout<<"Enter Luggage Size (Will be less than 32kg otherwise extra 500PK pays): ";
            cin>>luggageSize;
            if (luggageSize > 32) {
                extrapay = 500; 
                cout<<"Extra added due to over Luggage: "<<endl;
            } else {
                extrapay = 0;
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
class Ticket : public Airplane, public Passenger {
	public:
		Ticket(Airplane& flight) : Airplane(flight), Passenger() {
        FlightID = getNextFlightID();
    }
      

    static int getNextFlightID() {
        int lastID = 0;
        ifstream inFile("lastFlightID.txt");
        if (inFile.is_open()) {
            inFile >> lastID;
            inFile.close();
        }
        lastID++;
        ofstream outFile("lastFlightID.txt");
        if (outFile.is_open()) {
            outFile << lastID;
            outFile.close();
        }
        return lastID;
    }
    
    void bookTicket() {
    ofstream outFile("ticketFile.txt", ios::app); // Open file in append mode

    if (outFile.is_open()) {
        // Write flight details
        outFile << "\nPassport Number: " << passportNumber << endl;
        outFile << "First Name: " << Firstname << endl;
        outFile << "Last Name: " << Lastname << endl;
        outFile << "Email: " << email << endl;
        outFile << "Phone Number: " << phoneNumber << endl;
        outFile << "Plane ID: " << planeID << endl;
        outFile << "Plane Name: " << Planename << endl;
        outFile << "Time: " << time << endl;
        outFile << "Location: " << location << endl;
        outFile << "Price: " << (Price * TotalSeats) + extrapay << " PKR" << endl;
        outFile << "Seat Class: " << seatclass << endl;
        outFile << "Total Seats: " << TotalSeats << endl;
        outFile << "Luggage Size: " << luggageSize <<" kg"<< endl;

        cout << "Ticket booked successfully!" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}
void ViewTicket() {
	
    string passport;
    cout << "Enter your passport number: ";
    cin >> passport;

    ifstream inFile("ticketFile.txt");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find("Passport Number: " + passport) != string::npos) {
                found = true;
                cout << "Ticket Found!\n\n";
                // Print ticket details until a separator line is reached
                while (getline(inFile, line) && !line.empty() ){
                    cout << line << endl;
                }
                break;
            }
        }
        inFile.close();

        if (!found) {
            cout << "Ticket not found for passport number: " << passport << endl;
        }
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}
void cancelTicket() {
    string passportNumber;
    cout << "Enter your passport number: ";
    cin >> passportNumber;
    
    ifstream inFile("ticketFile.txt");
    ofstream tempFile("tempTicketFile.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find("Passport Number: " + passportNumber) != string::npos) {
                // Skip ticket information for the provided passport number
                found = true;
                while (getline(inFile, line) && !line.empty()) {
                    // Skip lines until an empty line is encountered
                }
            } else {
                // Write other ticket information to the temporary file
                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();
        
        if (found) {
            // Delete the original file
            remove("ticketFile.txt");
            // Rename the temporary file to the original file name
            rename("tempTicketFile.txt", "ticketFile.txt");
            cout << "Ticket canceled successfully!" << endl;
        } else {
            cout << "Ticket not found for passport number: " << passportNumber << endl;
        }
    } else {
        cout << "Unable to open file for reading or writing." << endl;
    }
}
void adminlogin() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        cout << "Admin login successful!" << endl;

        // Display list of planes
        cout << "\nAvailable Planes:\n";
        cout << "1. Plane ID: 123, Name: Plane123\n";
        cout << "2. Plane ID: 456, Name: Plane456\n";
        cout << "3. Plane ID: 789, Name: Plane789\n";
        cout << "4. Plane ID: 101, Name: Plane101\n";
        cout << "5. Plane ID: 112, Name: Plane112\n";
        cout << "6. Plane ID: 131, Name: Plane131\n";

        string planeID;
        cout << "\nEnter the plane ID to view bookings: ";
        cin >> planeID;

        // Read and display booking numbers from the file for the selected plane
        ifstream inFile("ticketFile.txt");
        if (inFile.is_open()) {
            string line;
            bool found = false;
            int totalBookings = 0;
            int economyBookings = 0;
            int businessBookings = 0;
            int firstBookings = 0;

            while (getline(inFile, line)) {
                if (line.find("Plane ID: " + planeID) != string::npos) {
                    found = true;
                    totalBookings++;
                    while (getline(inFile, line) && !line.empty()) {
                        if (line.find("Seat Class: Economy") != string::npos) {
                            economyBookings++;
                        } else if (line.find("Seat Class: Business") != string::npos) {
                            businessBookings++;
                        } else if (line.find("Seat Class: First") != string::npos) {
                            firstBookings++;
                        }
                    }
                }
            }
            inFile.close();

            if (found) {
                cout << "Total Bookings for Plane ID: " << planeID << " is " << totalBookings << endl;
                cout << "Economy Class Bookings: " << economyBookings << endl;
                cout << "Business Class Bookings: " << businessBookings << endl;
                cout << "First Class Bookings: " << firstBookings << endl;
            } else {
                cout << "No bookings found for Plane ID: " << planeID << endl;
            }
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    } else {
        cout << "Invalid admin credentials!" << endl;
    }
}


};
int main(){
	    Login obj1;

    int choice;
    cout << "Create New Account or Login" << endl;
    cout << "\n1: Create new account." << endl;
    cout << "2: Login." << endl;
    cin >> choice;
    
    system("cls");

    if (choice == 1) {
        cout << "Create New Account" << endl;
        obj1.createAccount();
        system("cls");
        cout << "Login" << endl;
        if (obj1.login() == false) {
            return 0;
        }
    } else if (choice == 2) {
        cout << "Login" << endl;
        if (obj1.login() == false) {
            return 0;
        }
    } else {
        cout << "Invalid choice." << endl;
        return 0;
    }
    
    system("cls");
    Airplane plane1("123", "Plane123", "2024-06-05 07:00am", "Karachi to Islamabad");
    Airplane plane2("456", "Plane456", "2024-06-05 12:00pm", "Lahore to Peshawar");
    Airplane plane3("789", "Plane789", "2024-06-05 08:00pm", "Islamabad to Quetta");
    Airplane plane4("101", "Plane101", "2024-06-05 07:00am", "Pakistan to Dubai");
    Airplane plane5("112", "Plane112", "2024-06-05 12:00pm", "Pakistan to Toronto");
    Airplane plane6("131", "Plane131", "2024-06-05 08:00pm", "Pakistan to London");

    int choice1;
    Airplane selectedFlight;
    cout << "Welcome to Air Management system." << endl;
    
    cout << "\n1. Book Ticket" << endl;
    cout << "2. View Tickets" << endl;
    cout << "3. Cancel Ticket" << endl;
    cout << "4. Admin Login" << endl;
    cout << "5. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice1;
    
    Passenger obj2;
    system("cls");
    
    switch (choice1) {
        case 1: {
            int choice2;
            cout << "Ticket Booking..." << endl;
            
            cout << "\n1. Domestic flights (within Pakistan)" << endl;
            
            cout << "2. International flights (outside Pakistan)" << endl;
            
            cout << "Enter your choice: ";
            cin >> choice2;
            
            
            system("cls");
            
            if (choice2 == 1) {
                int choice3;
                cout << "Ticket Booking..." << endl;
                cout << " Domestic flights (within Pakistan)" << endl;
                
                cout << "\n1. From Karachi to Islamabad." << endl;
                cout << "     Time: 2024-06-05 07:00am" << endl;
                
                cout << "\n2. From Lahore to Peshawar." << endl;
                cout << "     Time: 2024-06-05 12:00pm" << endl;
                
                cout << "\n3. From Islamabad to Quetta." << endl;
                cout << "     Time: 2024-06-05 08:00pm" << endl;
                cout << "Enter your choice: ";
                cin >> choice3;
                
                system("cls");
                
                if (choice3 == 1) {
                    cout << "Ticket Booking..." << endl;
                    plane1.setclassForDomesticflights(5000, 10000);
                    selectedFlight = plane1; 
                    
                } else if (choice3 == 2) {
                    cout << "Ticket Booking..." << endl;
                    plane2.setclassForDomesticflights(5000, 10000);
                    selectedFlight = plane2; 
                } else if (choice3 == 3) {
                    cout << "Ticket Booking..." << endl;
                    plane3.setclassForDomesticflights(5000, 10000);
                    selectedFlight = plane3; 
                } else {
                    cout << "Invalid choice." << endl;
                    return 0;
                }
                
            } else if (choice2 == 2) {
                int choice4;
                cout << "Ticket Booking..." << endl;
                cout << " International flights (outside Pakistan)" << endl;
                
                cout << "\n1. From Pakistan to Dubai." << endl;
                cout << "     Time: 2024-06-05 07:00am" << endl;
                
                cout << "\n2. From Pakistan to Toronto." << endl;
                cout << "     Time: 2024-06-05 12:00pm" << endl;
                
                cout << "\n3. From Pakistan to London." << endl;
                cout << "     Time: 2024-06-05 08:00pm" << endl;
                cout << "Enter your choice: ";
                cin >> choice4;
                
                system("cls");
                
                if (choice4 == 1) {
                    cout << "Ticket Booking..." << endl;
                    plane4.setclassForInternationalflights(50000, 100000, 200000);
                    selectedFlight = plane4;
                } else if (choice4 == 2) {
                    cout << "Ticket Booking..." << endl;
                    plane5.setclassForInternationalflights(50000, 100000, 200000);
                    selectedFlight = plane5; 
                } else if (choice4 == 3) {
                    cout << "Ticket Booking..." << endl;
                    plane6.setclassForInternationalflights(50000, 100000, 200000);
                    selectedFlight = plane6;
                } else {
                    cout << "Invalid choice." << endl;
                    return 0;
                }
            } else {
                cout << "Invalid choice." << endl;
                return 0;
            }
            
            Ticket obj3(selectedFlight);
            system("cls"); 
            obj3.setValue();
            system("cls");
            obj3.bookTicket();
            break;
        }
        case 2: {
            cout << "\nViewing Tickets...\n";
            Ticket obj3(selectedFlight); // Create a temporary Ticket object
            obj3.ViewTicket();
            break;
        }
        case 3:{
        	cout << "\nCanceling Ticket...\n";
            Ticket obj3(selectedFlight); // Create a temporary Ticket object
            obj3.cancelTicket();
            break;
		}
        case 4:{
        	cout << "\nAdmin Login...\n";
            Ticket t4(selectedFlight);
            t4.adminlogin();
			break;
		}
        case 5:{
        	cout << "\nExiting...\n";
            return 0;
			break;
		}
        default:{
        	cout << "\nInvalid choice. Please try again.\n";
			break;
		}
    }
}
