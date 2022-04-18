#include <iostream>
#include "reader.h"

int main(){

   std::string file_path = "../txt_tabs/boys_dont_cry.txt";
   Reader the_reader = Reader(file_path);
   //the_reader.print_vector();
   the_reader.translate_tabs();
   std::cout << the_reader.get_output_txt() << "\n";
   the_reader.export_output_to_txt("../output_txt/boys_dont_cry.txt");


    return 0;
};