
#include "parser.h"
using namespace std;
using namespace std::chrono;
int main(){
auto start = high_resolution_clock::now();
MainMenu();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<seconds>(stop - start);
cout << "Time taken for execution " << duration.count() << "seconds" << "\n";

  return 0;
}