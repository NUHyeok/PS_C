// O(n^2)
/*
int maxProfit(int* prices, int pricesSize) {
    int best_price = 0, ing  = 0, low = 10000;

    for (int i = 0; i < pricesSize - 1; i++){
        if(low > prices[i]) low = prices[i];
        else continue;
        
        for (int j = i+1; j < pricesSize; j++){
            if (ing < prices[j] - prices[i]){
                ing = prices[j] - prices[i];
            }
        }
        if (best_price < ing) best_price = ing;
    }

    return best_price;

}*/ 

// O(N)
int maxProfit(int* prices, int pricesSize) {
    int best_price = 0, low = 10000;

    for(int i = 0; i < pricesSize; i++){
        if(low > prices[i]) low = prices[i];
        if(best_price < prices[i] - low) best_price = prices[i] - low;
    }

    return best_price;
}