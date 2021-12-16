using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace RotationApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private void AngleSlider_AngleChanged(object _, double e)
            => UpdateAngle(XSlider.Angle, YSlider.Angle, e);

        private void YSlider_AngleChanged(object _, double e)
            => UpdateAngle(XSlider.Angle, e, ZSlider.Angle);

        private void XSlider_AngleChanged(object _, double e)
            => UpdateAngle(e, YSlider.Angle, ZSlider.Angle);

        private void UpdateAngle(double x, double y, double z)
        {
            float DegreesToRadius(double degree)
                => (float)((degree / 360) * 2 * Math.PI);

            DirectXPage.InputUpdate(DegreesToRadius(x), DegreesToRadius(y), DegreesToRadius(z)); 
        }
    }
}
