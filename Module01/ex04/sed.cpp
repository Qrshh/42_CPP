#include "sed.hpp"

//utilisation d'une reference pour pas avoir a recree la chaine(pas de copie) a chaque appel + c plus sur
void replace_line(std::string &line, const std::string &from, const std::string &to)
{
    if(from.empty()){
        std::cerr << "s1 is empty !" << std::endl;
        return ;
    }

    std::string new_string;
    size_t pos = 0;
    size_t len_s1 = from.length();
    while((pos = line.find(from, pos)) != std::string::npos)
    {
        new_string.append(line, 0, pos); //rajout de line jusqu'a la trouvaille de from dans la nouvelle string
        new_string.append(to); //rajout de la nouvelle chaine dans la nouvelle string 
        pos+= len_s1; //avance apres la correspondance de from
        line.erase(0, pos); //on supprime ce qu'on avait avant dans line
        pos = 0;
    }
    new_string.append(line); //plus d'occurence, on rajoute la fin de line dans la nouvelle string
    line.swap(new_string); //line devient new_string
}

void sed(char **av)
{
    std::string line;
    std::string outfile = std::string(av[1]) + ".replace";
    std::ifstream infile(av[1]);
    std::ofstream output(outfile.c_str());

    if(!infile){
        std::cerr << "Failed to open the input file" << std::endl;
        return ;
    }

    if(!output){
        std::cerr << "Failed to open the output file : " << outfile << std::endl;
        return ;
    }

    while(std::getline(infile, line)){
        replace_line(line, av[2], av[3]);
        output << line << std::endl;
    }
    infile.close();
    output.close();
}