int romanToInt(char* s) {
    int sum = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(i == 0){
            if(s[i] == 'I'){
            sum += 1;
            }
            else if(s[i] == 'V') sum += 5;
            else if(s[i] == 'X') sum += 10;
            else if(s[i] == 'L') sum += 50;
            else if(s[i] == 'C') sum += 100;
            else if(s[i] == 'D') sum += 500;
            else if(s[i] == 'M') sum += 1000;
        }
        else{
            if(s[i] == 'I'){
            sum += 1;
            }
            else if(s[i] == 'V') {
                if(s[i-1] == 'I') sum += 3;
                else sum += 5;
            }
            else if(s[i] == 'X') {
                if(s[i-1] == 'I') sum += 8;
                else sum += 10;
            }
            else if(s[i] == 'L') {
                if(s[i-1] == 'X') sum += 30;
                else sum += 50;
            }
            else if(s[i] == 'C') {
                if(s[i-1] == 'X') sum += 80;
                else sum += 100;
            }
            else if(s[i] == 'D') {
                if(s[i-1] == 'C') sum += 300;
                else sum += 500;
            }
            else if(s[i] == 'M') {
                if(s[i-1] == 'C') sum+= 800;
                else sum += 1000;
            }
        }

    }
        
    return sum;
}