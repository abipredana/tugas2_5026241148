#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class lemparanbola
{
public:
  const double g = 9.8;

  bool
  hitungsudut(double x, double y, double v, double &sudut1, double &sudut2)
  {
    double v_kuadrat = v * v;
    double diskriminan = v_kuadrat * v_kuadrat - g * (g * x * x + 2 * y * v_kuadrat);

    if (diskriminan < 0)
    {
      return false;
    }

    double akarkuadrat_diskriminan = sqrt(diskriminan);
    sudut1 = atan((v_kuadrat + akarkuadrat_diskriminan) / (g * x)) * 180 / M_PI;
    sudut2 = atan((v_kuadrat - akarkuadrat_diskriminan) / (g * x)) * 180 / M_PI;
    return true;
  }

  bool bacatarget(const string &filename, double &x, double &y)
  {
    ifstream file(filename);
    if (!file.is_open())
    {
      return false;
    }
    if (file >> x >> y)
    {
      cout << "Data di file target.txt dibaca: " << x << " " << y << endl; // Debugging output
    }
    else
    {
      cout << "Gagal membaca data target dari file target.txt" << endl;
    }
    file.close();
    return true;
  }
};

int main()
{
  lemparanbola bola;
  double x, y;
  double sudut1, sudut2;

  if (!bola.bacatarget("target.txt", x, y))
  {
    cout << "Gagal membaca file target." << endl;
    return 1;
  }

  double kecepatanawal;
  cout << "Masukkan kecepatan awal (m/s): ";
  cin >> kecepatanawal;

  if (bola.hitungsudut(x, y, kecepatanawal, sudut1, sudut2))
  {
    cout << "Target pada jarak " << x << " meter dan ketinggian " << y << " meter." << endl;
    cout << "Sudut elevasi yang diperlukan: " << sudut1 << " derajat atau " << sudut2 << " derajat." << endl;
  }
  else
  {
    cout << "Tidak ada sudut yang memungkinkan untuk mencapai target dengan kecepatan ini. (coba tambah kecepatan)" << endl;
  }

  return 0;
}
