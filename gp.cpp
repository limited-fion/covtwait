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
void add(Table_gp gp, std::vector<Table_gp> gp_db){
  gp_db.push_back(gp);
}


int main(){
    
  Table_gp gp;
  std::vector<Table_gp> gp_db;

  //input from GP
  std::cout << "GP postcode : ";
  std::cin >> gp.postcode;
 
  std::cout << "Number of vaccines currently available : ";
  std::cin >> gp.vaccine;

  //add GP details into gp database
  add(gp, gp_db);

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