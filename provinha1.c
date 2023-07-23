#include <stdio.h>
#include <stdlib.h>

float calcMed(float *vet, int n);

int main ( void ) 
{
	float *v; 
	float med = 0.0; 
	int i, n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n); 

    v = (float *) malloc(n * sizeof(float));

	/* leitura dos valores */
    printf("Digite os valores: ");
	for (i = 0; i < n; i++) 
		scanf("%f", &v[i]);

    med = calcMed(v, n);

	/* exibição do resultado */
	printf ("Media = %.2f \n", med);

    free(v);

	return 0;
}

float calcMed(float *vet, int n) {
    float med = 0.0;
    
    for(int i = 0; i < n; i++) {
        med += vet[i];
    }

    med /= n;

    return med;
}
