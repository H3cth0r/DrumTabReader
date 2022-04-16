#ifndef READER
#define READER

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>




class Reader{
    private:
        std::string                     file_name;
    protected:
        std::string                     output_txt;
        std::vector<std::string>        input_txt;

    public:
        Reader(){ 
        }
        Reader(std::string t_file_name){
            this->file_name     =       t_file_name;
            read_file();
        }

        // Getters
        std::string get_output_txt(){
            return output_txt;
        }
        // Setters
        // Additional methods
        void read_file(){
           std::fstream                 the_file;
           the_file.open(file_name, std::ios::in);

            std::string                 txt_line;
           // check if the file is open
           if(the_file.is_open()){
               while(getline(the_file, txt_line)){
                   input_txt.push_back(txt_line);
               }
           }
           the_file.close();
        }

        void print_vector(){
            for(int i = 0; i < input_txt.size(); i++){
                std::cout << input_txt[i] << "\n";
            }
        }

        void translate_tabs(){
            std::vector <char> tab_title;
            int length_tabs = input_txt[0].length();
            for(std::string i : input_txt){
                tab_title.push_back(i[0]);
            }

            // start reading the tab lines
            std::string combinations_iterator;
            char        character_iterator;
            bool        empty_ocurrence = false;
            bool        char_ocurrence  = false;
            int         tab_title_index = 0;
            for(int i = 1; i < length_tabs; i++){
                for(std::string j : input_txt){
                    character_iterator = j[i];
                    
                    // in case is "|" just break and add this
                    if(character_iterator == '|'){
                        combinations_iterator += "T";
                        tab_title_index = 0;
                        break;
                    }
                    // in cse is '-', then set empty_ocurrence to true and continue
                    if(character_iterator == '-'){
                        empty_ocurrence = true;
                    }else{
                        char_ocurrence = true;
                        combinations_iterator += tab_title[tab_title_index];
                    }
                    if(tab_title_index == tab_title.size()-1){
                        tab_title_index = 0;
                    }else tab_title_index++;
                }
                if(empty_ocurrence == true && char_ocurrence==false) combinations_iterator = '-';
                output_txt += combinations_iterator + ",";
                combinations_iterator = "";
                empty_ocurrence = false;
                char_ocurrence = false;
            }
        }
        bool export_output_to_txt(std::string file_name_and_path){
            std::ofstream outfile(file_name_and_path);
            outfile << output_txt << std::endl;
            outfile.close();
            return true;
        }
};


#endif