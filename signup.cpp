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


//add gp detail into vector
void add(Table_gp gp, std::vector<Table_gp>& gp_db){
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
    
  Table_gp gp;
  std::vector<Table_gp> gp_db;
  bool extra = false;

  Table_user user;
  std::vector<Table_user> user_db;

  //read gp data from gp database
  std::ifstream infile;
  infile.open("userdetailsdone.txt");
 
  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  Table_user tmp;
 
  while(infile >> tmp.name >> tmp.phone_no >> tmp.nhs_no >> tmp.gp_postcode){
      user_db.push_back(tmp);
  }
 
  infile.close();
  //


  //input from GP1
  std::cout << "GP postcode : ";
  std::cin >> gp.postcode;
 
  std::cout << "Number of vaccines currently available : ";
  std::cin >> gp.vaccine;
  std::cout << std::endl;
  
  if (gp.vaccine != 0){

    extra = true;
    //notify users
    //search users with the same postcode
    std::vector<int> n;
    search_contact(user_db, gp.postcode, n);

    //notify through text
    std::cout << "List of phone no of users nearby :" << std::endl;

    for(int i = 0; i < n.size(); i++){
      if (n.size() == 0){
        std::cout << "no users nearby" << std::endl;
      }

      //store users' phone no into a vector
      std::vector<long double> num_to_text;
      num_to_text.push_back(user_db[n[i]].phone_no);

      std::cout << user_db[n[i]].phone_no << std::endl;
    }
    std::cout << std::endl;
    std::cout << "[Text nearby users]" << std::endl << std::endl;
    
  }

  std::vector<int> n;
  search_contact(user_db, gp.postcode, n);

  std::string signup;

  //1st user receives example text
  if (extra == true){
    
    std::cout << "[Example text]" << std::endl;
    std::cout << "Hello " << user_db[n[0]].name << ", vaccines are available at your local GP at [time], would you like to book an appointment? Reply 'YES' or 'NO'" << std::endl;
    std::cin >> signup;
    std::cout << std::endl;
  }

  //change vaccine no when user sign up
  if (signup == "YES"){
    gp.vaccine--;
  }

  std::cout << "[Vaccines left : " << gp.vaccine << "]" << std::endl << std::endl;

  if (gp.vaccine == 0){
    std::cout << "[text nearby users]" << std::endl << std::endl;
    std::cout << "[Example text]" << std::endl;
    std::cout << "Vaccines are fully booked!" << std::endl;
  }

}