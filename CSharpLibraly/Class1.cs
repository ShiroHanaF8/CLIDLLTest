using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace CSharpLibraly
{
    public static class WPFClass
    {
        public static void CSMethod1()
        {
            try
            {
                System.Windows.MessageBox.Show("This is System.Windows.MessageBox", "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Information);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod2()
        {
            try
            {
                var UIelement = new DoubleCollection() { 1.1, 2.2, 3.3, 4.4 };
                System.Windows.MessageBox.Show("System.Windows.Media.DoubleCollection generated " + UIelement, "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Information);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod3()
        {
            try
            {
                Microsoft.Win32.OpenFileDialog dlg = new();
                dlg.Title = "This is Microsoft.Win32.OpenFileDialog";
                dlg.ShowDialog();
                System.Windows.MessageBox.Show(dlg.SafeFileName, "This is Microsoft.Win32.OpenFileDialog", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Information);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod4()
        {
            try
            {
                System.Windows.Forms.FolderBrowserDialog dlg = new();
                dlg.Description = "This is System.Windows.Forms.FolderBrowserDialog";
                dlg.ShowDialog();
                System.Windows.MessageBox.Show(dlg.SelectedPath, "System.Windows.Forms.FolderBrowserDialog", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Information);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod5()
        {
            try
            {
                System.Windows.Forms.OpenFileDialog dlg = new();
                dlg.Title = "This is System.Windows.Forms.OpenFileDialog";
                dlg.ShowDialog();
                System.Windows.MessageBox.Show(dlg.SafeFileName, "System.Windows.Forms.OpenFileDialog", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Information);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod6()
        {
            try
            {
                var UIelement = new Rectangle { X = 1, Y = 2, Width = 3, Height = 4 };
                System.Windows.MessageBox.Show("System.Drawing.Rectangle " + UIelement);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod7()
        {
            try
            {
                var UIelement = new System.Windows.Media.SolidColorBrush(System.Windows.Media.Color.FromRgb(0, 0, 0));
                System.Windows.MessageBox.Show("System.Windows.Media.SolidColorBrush generated " + UIelement);
            }
            catch (Exception ex)
            {
                System.Windows.MessageBox.Show(ex.ToString(), "", System.Windows.MessageBoxButton.OK, System.Windows.MessageBoxImage.Error);
            }
        }

        public static void CSMethod8()
        {
            Window1 window = new Window1();
            window.ShowDialog();

            //return "";
        }
    }
}
