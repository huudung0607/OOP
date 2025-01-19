class SV{
private:
    string ma, ten, ns, lop;
    double gpa;
public:
    void nhap(){
        getline(cin, ma);
        getline(cin, ten);
        getline(cin, ns);
        getline(cin, lop);
        cin >> gpa;
    }
    SV(string ma, string ten, string ns, string lop, double gpa){
        this->ma = ma;
        this->ten = ten;
        this->ns = ns;
        this->lop = lop;
        this->gpa = gpa;
    }
    void chuanHoaTen(){
        stringstream ss(ten);
        string res, w;
        while(ss >> w){
            res += toupper(w[0]);
            for(int i = 1; i < w.size(); i++){
                res += tolower(w[i]);
            }
            res += " ";
        }
        res.pop_back();
        ten = res;
    }
    void chuanHoaNS(){
        if(ns[1] == '/') ns = "0" + ns;
        if(ns[4] == '/') ns.insert(3, "0");
    }
void in(){
        cout << ma << " " << ten << " " << ns << " " << lop << " " << fixed << setprecision(2) << gpa << endl;
    }
    double getGpa(){
        return gpa;
    }
    string getMa(){
        return ma;
    }
};

bool cmp(SV x, SV y){
    if(x.getGpa() != y.getGpa())
        return x.getGpa() > y.getGpa();
    return x.getMa() < y.getMa();
}

int main(){
    vector<SV> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin.ignore();
        string ma, ten, ns, lop; double gpa;
        getline(cin, ma);
        getline(cin, ten);
        getline(cin, ns);
        getline(cin, lop);
        cin >> gpa;
        SV s(ma, ten, ns, lop, gpa);
        s.chuanHoaTen();
        s.chuanHoaNS();
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(SV x : v){
        x.in();
    }
}
