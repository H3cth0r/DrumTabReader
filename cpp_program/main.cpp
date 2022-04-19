#include <iostream>
#include "reader.h"
#include <vector>
#include <string>

int main(){

//    std::vector<std::string> song_list = {"back_in_black",
//                                          "boys_dont_cry",
//                                          "du_hast",
//                                          "feel_good_inc",
//                                          "fortunate_son",
//                                          "paranoid",
//                                          "seven_nation_army",
//                                          "when_the_sun_goes_down",
//                                          "you_look_good_on_the_dancefloor"};

//    std::string file_paths = "../txt_tabs/";
//    std::string output_path = "../output_txt/";
//    std::cout << "lol" << "\n";
//    for(std::string i : song_list){
//        std::cout << ">>> song: " << i << "\n";
//        Reader tab_reader = Reader(file_paths + i + ".txt");
//        tab_reader.translate_tabs();
//        tab_reader.export_output_to_txt(output_path + i + ".txt");
//    } 
   std::string file_path = "../txt_tabs/du_hast.txt";
   Reader the_reader = Reader(file_path);
   //the_reader.print_vector();
   the_reader.translate_tabs();
   std::cout << the_reader.get_output_txt() << "\n";
   the_reader.export_output_to_txt("../output_txt/du_hast.txt");


    return 0;
};