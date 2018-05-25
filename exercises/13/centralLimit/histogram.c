int histogram ()
{
	//bins, min, max
	TH1F *h1 = new TH1F("h1", "histo_snakes_crandom",200, 0., 1.);
	FILE *fp = fopen("20.txt","r");
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
