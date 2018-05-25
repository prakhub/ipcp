int histogram ()
{
	TH1F *h1 = new TH1F("h1", "histo_snakes_crandom",100, 0., 100.);
	FILE *fp = fopen("81","r");
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
