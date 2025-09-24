bool canConstruct(char* ransomNote, char* magazine) {

    for(int i = 0; ransomNote[i] != '\0'; i++){
        int is = 0;
        for(int j= 0; magazine[j] != '\0'; j++){
            if(ransomNote[i] == magazine[j]) {
                magazine[j] = '0'; 
                is = 1;
                break;
            }
        }
        if(is == 0) return false;
    }

    return true;
}