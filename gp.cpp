#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>


//data of GP's postcode and number of vaccines available
struct Table_gp{
  std::string postcode;
  int vaccine;
};

//add gp detail into vector
void add(Table_gp gp, std::vector<Table_gp>& gp_db){
  gp_db.push_back(gp);
}


int main(){
    
  Table_gp gp1, gp2;
  std::vector<Table_gp> gp_db;

  //input from GP1
  std::cout << "GP postcode : ";
  std::cin >> gp1.postcode;
 
  std::cout << "Number of vaccines currently available : ";
  std::cin >> gp1.vaccine;

  //add GP1 details into gp database
  add(gp1, gp_db);


  //input from GP2
  std::cout << "GP postcode : ";
  std::cin >> gp2.postcode;
 
  std::cout << "Number of vaccines currently available : ";
  std::cin >> gp2.vaccine;

  //add GP2 details into gp database
  add(gp2, gp_db);


  //store into "gpdetails.txt"

  std::ofstream outfile;
  outfile.open("gpdetails.txt");

  if(!outfile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  for(int i = 0; i < gp_db.size(); i++){
    outfile << gp_db[i].postcode << "\t" << gp_db[i].vaccine << std::endl;
  }
  outfile.close();

}
