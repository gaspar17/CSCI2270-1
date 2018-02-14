#include <iostream>
#include <fstream> //file stream
#include <sstream> //string stream
using namespace std;

struct Sale{
    //type, sale/want, price
    string type;
    int desire;
    int price;
    Sale(){}
    Sale(string t, int d, int p){
      type = t;
      desire = d;
      price = p;
    }
};

int main(int argc, char *argv[]){

  int x;
  int saleCount = 0;
  string fileName = argv[1];

  Sale saleArray[100];
  ifstream saleStream;
  saleStream.open(fileName.c_str());

  if(saleStream.is_open()){
    string line;
    int counter = 0;

    while(getline(saleStream, line)){
      stringstream ss;
      ss << line;
      string item;

      //get type
      getline(ss, item, ',');
      saleArray[counter].type = item;

      //get desire
      getline(ss, item, ',');
      if(item == " wanted"){
        saleArray[counter].desire = 1; //wanted = 1;
      }
      else if(item == " for sale"){
        saleArray[counter].desire = 0; //for sale = 0
      }
      else{
        cout << "Error declaring desire. Seller/buyer status incorrectly defined in file" << endl;
      }

      //get price
      getline(ss, item, ',');
      saleArray[counter].price = stoi(item);

      //cout << saleArray[counter].type << "  " << saleArray[counter].desire << "  " << saleArray[counter].price << endl;
      //check for matches
      if(counter > 0){

        if(saleArray[counter].desire == 1){ //if buyer
          for(x = 0; x < counter; x++){
            if((saleArray[x].type == saleArray[counter].type) && (saleArray[x].desire != saleArray[counter].desire) && (saleArray[x].price <= saleArray[counter].price)){ //if a match is found that satisfies purchase

              cout << saleArray[x].type << " " << saleArray[x].price << endl;

              //shift array to delete x
              int i;
              for(i = x; i < counter-1; i++){
                saleArray[i] = saleArray[i+1];
              }
              counter--;
              saleCount++;

              break;

            }
          }
        }

        else if(saleArray[counter].desire == 0){ //if seller
          for(x = 0; x < counter; x++){
            if((saleArray[x].type == saleArray[counter].type) && (saleArray[x].desire != saleArray[counter].desire) && (saleArray[x].price >= saleArray[counter].price)){ //if a match is found that satisfies sale

              cout << saleArray[x].type << " " << saleArray[counter].price << endl;

              //shift array to delete x
              int i;
              for(i = x; i < counter-1; i++){
                saleArray[i] = saleArray[i+1];
              }
              counter--;
              saleCount++;

              break;

            }
          }
        }
      }

      //increment counter
      counter++;

    }

    //Output

    cout << "Items sold." << endl;
    cout << saleCount << endl;

      cout << "Items remaining in the message board after reading all lines in the file." << endl;
    for(x = 0; x < counter; x++){
      if(saleArray[x].desire == 1){
        cout << saleArray[x].type << ", " << "wanted" << ", " << saleArray[x].price << endl;
      }
      else if(saleArray[x].desire == 0){
        cout << saleArray[x].type << ", " << "for sale" << ", " << saleArray[x].price << endl;
      }
    }
  }

  else{
    cout << "Error reading file, file may not be open" << endl;
  }

}
