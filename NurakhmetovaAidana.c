#include <stdio.h>

/*This is a struct called Order.
Variables are declared inside it.*/
typedef struct {
	int id;
	int day;
	int quantity;
	char type[60];
	double total_cost;
	char arrangement[80];
	char payment[60];
	int delivery;
	char courier[60];
} Order;


int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	FILE *file;
	file = fopen("flowerSales.txt","r"); //Reads from the file.

	if (file == NULL) {
		printf("Problem opening file.");
		return 1;  //If the file is not found then give an error.
	}

	Order record[200]; // This is an array of struct Order.
	int i=0; // "i" shows the number of a row.
	do {
		//Reading the data from the file.
		fscanf(file,"%i %i %i %s %lf %s %s %i %s", &record[i].id, &record[i].day,
			   &record[i].quantity, record[i].type, &record[i].total_cost,
			   record[i].arrangement, record[i].payment,
			   &record[i].delivery, record[i].courier);

		//Printing the data into the Console window.
		printf("%i %i %i %s %f %s %s %i %s\n", record[i].id, record[i].day,
				record[i].quantity, record[i].type, record[i].total_cost,
				record[i].arrangement, record[i].payment, record[i].delivery,
				record[i].courier);

		i++; //Go to the next row.
	} while(!feof(file)); /*Output a line of the file,
	                         until the end is reached.*/
	i--; //Go back to the previous row.

	int n; //"n" shows the day number.
	do {
		printf("Which day do you want to see?");
		scanf("%i", &n); //Asks the user to input the day.
		if(n<0 || n>31){
			printf ("You entered a number outside the range.");
			break; //The program is ended.
		}
		int j; //"j" is another letter to show the row number.
		/*Variable declarations
		and assigning initial values to them.*/
		int numberofOrder=0;
		int totalAmount=0;
		int numberofBouquets=0;
		int numberofGifts=0;
		double totalCost=0, cash=0;
		double Epay_Kazkom=0, web_money=0;
		double halyq_bank=0, yandex_money=0;
		double qiwi=0, PayPal=0;
		int numberofDelivery=0, totalDeliveryCost=0;
		int shapaghat=0, qanat_agha=0, azat=0;
    	for(j=0; j<=(i-1); j++){
    		/*If today is the day that you chose,
    		increase the amount of orders by 1 each time the given day is encountered.*/
    		if(record[j].day == n){
    			numberofOrder+=1;
    			totalAmount+=record[j].quantity; //Add all quantities of flowers purchased for this day.

    			char a[]="small_bouquet"; //This an array that stores strings as its elements.
    			char b[]="big_bouquet";
    			/*If the type of flower is equal to a small
    			or big bouquet, count the bouquets for this day.*/
    			if(strcmp(record[j].type, a)== 0 || strcmp(record[j].type, b)==0){
    				numberofBouquets++;
    			}

    			char c[]="gift";
    			//If the type of flower is a "gift", count gifts for this day.
    			if(strcmp(record[j].type, c)== 0){
    				numberofGifts++;
    			}

    			totalCost+=record[j].total_cost; //Shows the total cost of the orders.
    			/*Again comparing two strings using the C library
    			 function strcmp()to show the type of payment.*/
    			if(strcmp(record[j].payment, "cash")==0){
    				cash+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "Epay_Kazkom")==0){
    				Epay_Kazkom+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "web_money")==0){
    				web_money+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "halyq_bank")==0){
    				halyq_bank+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "yandex_money")==0){
    				yandex_money+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "qiwi")==0 || strcmp(record[j].payment, "Qiwi")==0){
    				qiwi+=record[j].total_cost;
    			} else if(strcmp(record[j].payment, "paypal")==0){
    			  PayPal+=record[j].total_cost;
    			}
    			/*If the order has not been picked up,
    			count the number of deliveries and the total cost for them.*/
    			if(strcmp(record[j].courier, "pickup")!=0){
    				numberofDelivery++;
    				totalDeliveryCost+=record[j].delivery;
    				/*If a courier is Shapaghat/Qanat agha/Azat,
    				 count their deliveries for today.*/
    				if(strcmp(record[j].courier, "shapaghat")==0){
    					shapaghat++;
    				} else if(strcmp(record[j].courier, "qanat_agha")==0){
    					qanat_agha++;
    				} else if(strcmp(record[j].courier, "azat")==0){
    					azat++;
    				}
    			}


    		}

    	}
    	//Printing all the outputs to the Console window.
    	printf("Total number of orders: %i\n", numberofOrder);
    	printf("%i flowers were purchased today.\n", totalAmount);
    	printf("The number of bouquets purchased today: %i \n", numberofBouquets);
    	printf("The number of gifts purchased today: %i \n", numberofGifts);
    	printf("Total cost of orders for today: %.2lf \n", totalCost);
    	printf("Total cost paid:");
    	printf("\nCash: %.2lf  \n", cash);
    	printf("Epay_Kazkom: %.2lf \n", Epay_Kazkom);
    	printf("Web_money: %.2lf  \n", web_money);
    	printf("Halyq Bank: %.2lf  \n", halyq_bank);
    	printf("Yandex_money: %.2lf  \n", yandex_money);
    	printf("Qiwi: %.2lf  \n", qiwi);
    	printf("PayPal: %.2lf \n", PayPal);
    	printf("The amount of Deliveries made today: %i \n",numberofDelivery);
    	printf("Total cost for Delivery: %i \n", totalDeliveryCost);
    	if (shapaghat>qanat_agha && shapaghat>azat) {
    		printf ("Shapaghat made the most deliveries today. The number of deliveries: %i \n ", shapaghat);
    	} else if (qanat_agha>shapaghat && qanat_agha>azat ){
    		printf ("Qanat Agha made the most deliveries today. The number of deliveries: %i \n ", qanat_agha);
    	} else if(azat>shapaghat && azat>qanat_agha){
    		printf ("Azat made the most deliveries today. The number of deliveries: %i \n ", azat);
    	} else if (shapaghat == qanat_agha && shapaghat>azat){
    		printf ("Shapaghat and Qanat Agha made the most deliveries today. The number of deliveries: %i \n ", shapaghat);
    	} else if (shapaghat == azat&& shapaghat>qanat_agha){
    		printf ("Azat and Shapaghat made the most deliveries today. The number of deliveries: %i \n ", azat);
    	}else if (qanat_agha == azat && azat>shapaghat) {
    		printf ("Azat and Qanat Agha made the most deliveries today. The number of deliveries: %i \n ", azat);
    	} else if ((qanat_agha == azat) && (azat == shapaghat)) {
    		printf ("All couriers made equal deliveries today. The amount of deliveries: %i \n ", azat);
    	}
	} while(1); /*This is used to loop infinitely.
	             Specifically, here it is used to ask the user
	             to input another day over and over again.*/

	fclose(file);
    return 0;

}

