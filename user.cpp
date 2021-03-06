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
  double phone_no;
  double nhs_no;
  std::string gp_postcode;
};


//add user detail into vector
void adduser(Table_user user, std::vector<Table_user>& user_db){
  user_db.push_back(user);
}


std::string point_to_s(Table_user user){
    return "(" + user.name + std::to_string(user.phone_no) + ", " + std::to_string(user.nhs_no) + ")";
}


int main(){
    
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
  adduser(user, user_db);

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

}
