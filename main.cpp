#include <iostream>
#include <fstream>

int32_t file_number;
std::string output_file_name;
std::string file_name;

std::string getNextOutput_fileName();

int main(int argc, char ** argv) {

    std::string first_line;
    std::string buffer_line;

    int32_t current_line;
    int32_t max_lines;

    if(argc==1){
        perror("to be used as ");
        perror(argv[0]);
        perror(" file_name \n");
        exit(1);
    }
    if(argc==2){
        file_name = std::string(argv[1]);
        max_lines = 1,000,000;
    }

    std::ifstream input_file(file_name);
    std::getline(input_file, first_line);

    file_name = file_name.replace(file_name.end()-4,file_name.end(),"");

    file_number = 0;

    std::ofstream output_file(getNextOutput_fileName());
    output_file.write(first_line.c_str(),first_line.length());
    current_line = 0;

    while(!input_file.eof()) {
        current_line++;
        std::getline(input_file, buffer_line);

        output_file.write(buffer_line.c_str(),buffer_line.length());

        if(current_line>max_lines){
            output_file.close();
            current_line = 0;
            output_file = std::ofstream(getNextOutput_fileName());
            output_file.write(first_line.c_str(),first_line.length());
        }

    }

    if(output_file.is_open())
        output_file.close();

    return 0;
}


std::string getNextOutput_fileName(){

    file_number++;
    output_file_name = file_name+" ";
    output_file_name += file_number+".csv";

}
