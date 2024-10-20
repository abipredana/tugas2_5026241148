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
