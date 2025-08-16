#include "protein_translation.h"
#include <map>

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(std::string protein){
    std::map<std::string, std::string> codon_to_aa = {
        {"AUG" , "Methionine"},
        {"UUU" , "Phenylalanine"},
        {"UUC" , "Phenylalanine"},
        {"UUA" , "Leucine"},
        {"UUG" , "Leucine"},
        {"UCU" , "Serine"},
        {"UCC" , "Serine"},
        {"UCA" , "Serine"},
        {"UCG" , "Serine"},
        {"UAU" ,"Tyrosine"},
        {"UAC" , "Tyrosine"},
        {"UGU" , "Cysteine"},
        {"UGC" , "Cysteine"},
        {"UGG" , "Tryptophan"},
        {"UAA" , "STOP"},
        {"UAG" , "STOP"},
        {"UGA" , "STOP"}
    };
    std::vector<std::string> amino_acids;
    int i = 0;
    std::string codon = "";
    for(auto p : protein){
        codon += p;
        i += 1;
        if(i > 2){
            std::string aa = codon_to_aa[codon];
            if("STOP" != aa){
                amino_acids.push_back(aa);
                i = 0;
                codon = "";
            }else{
                return amino_acids;
            }
        }
    }
    return amino_acids;
}

}  // namespace protein_translation
