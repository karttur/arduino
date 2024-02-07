/*
 * 
 * 
 */

/*
 void ArrayMeanStd(uint16_t a[], int n) 
{   
    // Compute mean (average of elements) 
    double sum = 0; 
    for (int i = 0; i < n; i++) sum += a[i];  
    arrayMean = (float)sum / (float)n; 
    // Compute sum squared differences with mean. 
    double sqDiff = 0; 
    for (int i = 0; i < n; i++) 
        sqDiff += (a[i] - arrayMean) * (a[i] - arrayMean); 
    arrayStd = sqrt((float)sqDiff / n); 
} */

 void ArrayMeanStd(uint16_t a[], int n, float &Mean, float &Std) 
{   
    // Compute mean (average of elements) 
    double sum = 0; 
    for (int i = 0; i < n; i++) sum += a[i];  
    Mean = (float)sum / (float)n; 
    // Compute sum squared differences with mean. 
    double sqDiff = 0; 
    for (int i = 0; i < n; i++) 
        sqDiff += (a[i] - Mean) * (a[i] - Mean); 
   Std = sqrt((float)sqDiff / n); 
}


/*
struct t_MeanStdStruct {
    float mean;
    float std;
};

t_MeanStdStruct GetMeanStd(uint16_t a[], int n) {   
   t_MeanStdStruct stats;
   
    // Compute mean (average of elements) 
    float sum = 0; 
    for (int i = 0; i < n; i++) sum += a[i];  
    arrayMean = (float)sum / (float)n; 
    // Compute sum squared differences with mean. 
    float sqDiff = 0; 
    for (int i = 0; i < n; i++) 
        sqDiff += (a[i] - arrayMean) * (a[i] - arrayMean); 
    arrayStd = sqrt((float)sqDiff / n); 
    stats.mean = arrayMean;
    stats.std = arrayStd;
}*/
