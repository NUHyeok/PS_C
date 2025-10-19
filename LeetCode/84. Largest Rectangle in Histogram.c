int stack[100001];
int largestRectangleArea(int* heights, int heightsSize) {
    int top = -1;
    int maxArea = 0;

    for(int i = 0; i <= heightsSize; i++){
        int heightcurrent = (i == heightsSize) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] > heightcurrent){
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }
    return maxArea;
}