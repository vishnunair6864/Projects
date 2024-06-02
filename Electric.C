{
const int n=5;
const int m=10;
float dx=0.5;
float Ex[n][n];
float Ey[n][n];
float xh=1.0;
float xl=-1.0;
float yh=1.0;
float yl=-1.0;
float Vnew[n][n];
float Vold[n][n];
float dV[n][n];
float e=0.0001;
float p[n][n];
float E0=1.0;
float pi=TMath::Pi();
float a=2.0/(1.0+(pi/n));

cout<<"ok"<<endl;
flush(cout);


TCanvas*c1=new TCanvas("c1","Electric Potential Around a Point Charge",10,10,800,400);
c1->cd();
TH2D*hist=new TH2D("hist","Electric Potential Around a Point Charge",n,xl,xh,n,yl,yh);
TH2D*hist2=new TH2D("hist2","Electric Field",n,-1.0,1.0,n,-1.0,1.0);
TCanvas*c2=new TCanvas("c2","Electric Field and Potential Around a Point Charge",10,10,1200,400);
c2->Divide(2,1);
TArrow*A=new TArrow(0.0,0.0,1.0,1.0,003,">");

cout<<"ok"<<endl;

//initial conditions
for(int j=0;j<n;j++)
{
for(int i=0;i<n;i++)
{
Vnew[0][j]=0.0;
Vnew[i][0]=0.0;
Vnew[n-1][j]=0.0;
Vnew[i][n-1]=0.0;
Vold[0][j]=0.0;
Vold[i][0]=0.0;
Vold[n-1][j]=0.0;
Vold[i][n-1]=0.0;
p[i][j]=0.0;
p[n/2][n/2]=4.0;
}
}

cout<<"ok"<<endl;

///solution with Gauss-Seidel Method
for(int t=0;t<10;t++)
{
for(int j=0;j<n;j++)
{
for(int i=0;i<n;i++)
{
Vnew[i][j]=(1.0/4.0)*(Vold[i+1][j]+Vnew[i-1][j]+Vold[i][j+1]+Vnew[i][j-1])+((p[i][j]*dx*dx)/4.0*E0);
Ex[i][j]=-(Vold[i+1][j]-Vnew[i-1][j])/(2.0*dx);
Ey[i][j]=-(Vold[i][j+1]-Vnew[i][j-1])/(2.0*dx);
}
}
}


//Jacobi Method with Over-Relaxation Method
for(int j=0;j<n;j++)
{
for(int i=0;i<n;i++)
{
dV[i][j]=dV[i][j]+(Vnew[i][j]-Vold[i][j]);
if((Vnew[i][j]-Vold[i][j])>e)
{
Vold[i][j]=Vnew[i][j]+(a*dV[i][j]);
}
else
{
break;
}
hist->SetBinContent(i+1,j+1,Vold[i][j]);
}
}


//graphs
c1->cd();
hist->Draw("surf");
return;
c2->cd(1);

TF1*f1=new TF1("f1","[1]/(4.0*[2]*[3]*x)",0.0,1.0);
f1->SetParameters(1.0,pi,E0);
f1->Draw("same");

c2->cd(2);
hist2->Draw();

float x=0,y=0;
for(int j=0;j<n;j++)
{
for(int i=0;i<n;i++)
{


auto mm= new TMarker(x,y,20);
mm->Draw("same");


}
}
}
