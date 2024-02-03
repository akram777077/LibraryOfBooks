#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
namespace files
{
    std::string livreToString(const Livre& livre, const std::string& separator)
    {
        std::stringstream ss;
        ss << livre.numero << separator
            << livre.titre << separator
            << livre.auteur << separator
            << livre.anneeEdition << separator
            << livre.exemplaires;
        return ss.str();
    }
    std::vector<std::string> split(const std::string& input, const std::string& separator) 
    {
        std::vector<std::string> result;
        size_t start = 0, end = 0;

        while ((end = input.find(separator, start)) != std::string::npos) {
            result.push_back(input.substr(start, end - start));
            start = end + separator.length();
        }

        result.push_back(input.substr(start));

        return result;
    }
    Livre stringToLivre(std::string& input, const std::string& separator)
    {
        Livre result;
        std::vector<std::string> data = split(input, separator);
        result.numero = std::stoi(data[0]);
        result.titre = data[1];
        result.auteur = data[2];
        result.anneeEdition = std::stoi(data[3]);
        result.exemplaires = std::stoi(data[4]);
        return result;
    }
    void writeToTextFile(const std::string& fileName, const std::string& content)
    {
        std::ofstream outputFile(fileName,std::ios::app | std::ios::out);
        if (outputFile.is_open()) {
            outputFile << content;
            outputFile.close();
        }
    }
    std::vector<std::string> readFile(const std::string& fileName) 
    {
        std::vector<std::string> fileContents;
        std::ifstream fileStream(fileName);
        if (fileStream.is_open()) {
            std::string line;
            while (std::getline(fileStream, line)) {
                fileContents.push_back(line);
            }
            fileStream.close();
        }
        else {
            std::cerr << "Unable to open file: " << fileName << std::endl;
        }

        return fileContents;
    }
    void save(NoeudArbre* head,std::string fileName)
    {
        std::vector<std::string> temp;
        part1::forEchLivresIN(head, [&](const Livre& x) {temp.push_back(files::livreToString(x,"//##//"));});
        for(auto& i:temp)
            writeToTextFile(fileName, i);
    }
    void load(NoeudArbre* &head,std::string fileName)
    {
        std::vector<std::string> data = readFile(fileName);
        for (auto& i : data)
        {
            head=part1::insererLivre(head, stringToLivre(i,"//##//"));
        }
    }

}