//run with: root histogram.c
int histogram ()
{
	//title, #bins, min, max
	TH1F *h1 = new TH1F("h1", "Histogram of InverseCDF",200, 0., 3.2);
	FILE *fp = fopen("12.txt","r");
	float data;
	while (!feof(fp)) {
		fscanf(fp,"%f",&data);
		h1->Fill(data);
	}
	fclose(fp);
	
	h1->GetXaxis()->SetTitle("Value");
	h1->GetYaxis()->SetTitle("# of entries");
	h1->Draw();
	
	return 0;
}
