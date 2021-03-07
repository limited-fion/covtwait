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
    for(int i = 0; i < n.size(); i++){
      if (n.size() == 0){
        std::cout << "no users nearby" << std::endl;
      }

      std::vector<long double> num_to_text;
        num_to_text.push_back(user_db[n[i]].phone_no);
    }
    std::cout << "[text nearby users]" << std::endl;
  }

  //add GP1 details into gp database
  add(gp, gp_db);

}