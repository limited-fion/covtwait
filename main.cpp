#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

//data of GP's postcode and number of vaccines available
struct Table_gp{
  std::string postcode;
  int vaccine;
};

//user data
struct Table_user{
  std::string name;
  unsigned long phone_no;
  unsigned long nhs_no;
  std::string gp_postcode;
};


//add user detail into vector
void add_user(Table_user user, std::vector<Table_user>& user_db){
  user_db.push_back(user);
}


//add gp detail into vector
void add_gp(Table_gp gp, std::vector<Table_gp>& gp_db){
  gp_db.push_back(gp);
}


//return the number of vectors that have postcode
int no_contact(const std::vector<Table_user>& user, std::string postcode){

  int x = 0;

  for (int i=0; i < user.size(); i++){
    if (user[i].gp_postcode == postcode){
      x++;
    }
  }
  return x;
}


//return the index of vector when given postcode
void search_contact(const std::vector<Table_user>& user, std::string postcode, std::vector<int>& n){

  for (int j=0; j < user.size(); j++){  
    if (user[j].gp_postcode == postcode){
      n.push_back(j);
    }
  }
}

int main(){

  std::cout << "Welcome to COV'T Wait!" << std::endl << std::endl;


  std::cout << "Everytime a user signs up, run [user.cpp], which reads input from user and writes to userdetails.txt" << std::endl << std::endl << "Try sign up as an user!" << std::endl << std::endl ;

   //input from user
  Table_user user;
  std::vector<Table_user> user_db;

  std::cout << "Name : ";
  std::cin >> user.name;
 
  std::cout << "Contact number : ";
  std::cin >> user.phone_no;

  std::cout << "NHS number : ";
  std::cin >> user.nhs_no;

  std::cout << "Your GP postcode : ";
  std::cin >> user.gp_postcode;
  
  //add user details into user database
  add_user(user, user_db);

  //store into "userdetails.txt"

  std::ofstream outfile;
  outfile.open("userdetails.txt");

  if(!outfile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  for(int i = 0; i < user_db.size(); i++){
    outfile << user_db[i].name << "\t" << user_db[i].phone_no << "\t" << user_db[i].nhs_no << "\t" << user_db[i].gp_postcode << std::endl;
  }

  outfile.close();
  std::cout << std::endl;
  //


  //
  std::cout << "When done, an example users' details file : " << std::endl << std::endl;

  std::vector<Table_user> user_db1;

  std::ifstream infile;
  infile.open("userdetailsdone.txt");
 
  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  Table_user tmp;
 
  while(infile >> tmp.name >> tmp.phone_no >> tmp.nhs_no >> tmp.gp_postcode){
      user_db1.push_back(tmp);
  }
 
  infile.close();

  std::cout << "Name" << "\t" << "Phone no" << "\t" << "NHS number" << "\t" << "Postcode" << std::endl;

  for (int i = 0; i<user_db1.size(); i++){
    std::cout << user_db1[i].name << "\t" << std::to_string(user_db1[i].phone_no) << "\t" << std::to_string(user_db1[i].nhs_no) << "\t" << user_db1[i].gp_postcode << std::endl;
  }
  std::cout << std::endl;
  //


  //  
  std::cout << "When GP realise there are extra vaccines (anytime during the day), run [gp.cpp], write to gpdetails.txt" << std::endl << std::endl << "Try reporting on behalf of GP!" << std::endl << std::endl;

  Table_gp gp1;
  std::vector<Table_gp> gp_db;

  //input from GP1
  std::cout << "GP postcode : ";
  std::cin >> gp1.postcode;
 
  std::cout << "Number of vaccines currently available : ";
  std::cin >> gp1.vaccine;
  std::cout << std::endl;

  //add GP1 details into gp database
  add_gp(gp1, gp_db);

  //store into "gpdetails.txt"

  std::ofstream outfile1;
  outfile1.open("gpdetails.txt");

  if(!outfile1.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  for(int i = 0; i < gp_db.size(); i++){
    outfile1 << gp_db[i].postcode << "\t" << gp_db[i].vaccine << std::endl;
  }
  outfile1.close();
  //


  //
  std::cout << "When done, an example GPs' details file : " << std::endl << std::endl;

  std::vector<Table_gp> gp_db1;

  std::ifstream infile1;
  infile1.open("gpdetailsdone.txt");
 
  if(!infile1.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  Table_gp tmp1;
 
  while(infile1 >> tmp1.postcode >> tmp1.vaccine){
      gp_db1.push_back(tmp1);
  }
 
  infile.close();

  std::cout << "Postcode" << "\t" << "No of vaccines available" << std::endl;

  for (int i = 0; i<gp_db1.size(); i++){
    std::cout << gp_db1[i].postcode << "\t" << " " << "\t" << gp_db1[i].vaccine << std::endl;
  }
  std::cout << std::endl;
  //


  //
  std::cout << "Notify users, run [notify.cpp]..." << std::endl << std::endl;

  bool extra;

  if (gp1.vaccine != 0){
    
    extra = true;
    //notify users
    //search users with the same postcode
    std::vector<int> n;
    search_contact(user_db1, gp1.postcode, n);

    //notify through text
    for(int i = 0; i < n.size(); i++){
      if (n.size() == 0){
        std::cout << "no users nearby" << std::endl;
      }

      std::vector<unsigned long> num_to_text;
        num_to_text.push_back(user_db1[n[i]].phone_no);
    }
    std::cout << "[Text nearby users]" << std::endl << std::endl;
  }
  //


  //
  std::cout << "Run [signup.cpp]..." << std::endl << std::endl;

  std::string signup;

  //1st user receives example text
  if (extra == true){
    std::vector<int> n;
    search_contact(user_db1, gp1.postcode, n);
    
    std::cout << "[Example text]" << std::endl;
    std::cout << "Hello " << user_db1[n[0]].name << ", vaccines are available at your local GP at [time], would you like to book an appointment? Reply 'YES' or 'NO'" << std::endl;
    std::cin >> signup;
    std::cout << std::endl;
  }

  //change vaccine number when user sign up
  if (signup == "YES"){
    gp1.vaccine--;
    std::cout << "You booked a spot! Please wear a face mask and follow social distancing rules. See you later!" << std::endl << std::endl;
  }

  

  std::cout << "[Vaccines left at " << gp1.postcode << " = " << gp1.vaccine << "]" << std::endl << std::endl;

  if (gp1.vaccine == 0){
    std::cout << "[Text nearby users]" << std::endl << std::endl;
    std::cout << "[Example text]" << std::endl;
    std::cout << "Vaccines are fully booked!" << std::endl;
  }
  //

}