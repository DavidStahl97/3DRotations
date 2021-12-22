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

            UpdateAngle(XSlider.SlideValue, YSlider.SlideValue, ZSlider.SlideValue);
            UpdateCamera(PhiSlider.SlideValue, EpsilonSlider.SlideValue, DistanceSlider.SlideValue);
        }

        private void ZSlider_AngleChanged(object _, ValueChangedEventArgs<int> e)
            => UpdateAngle(XSlider.SlideValue, YSlider.SlideValue, e.Value);

        private void YSlider_AngleChanged(object _, ValueChangedEventArgs<int> e)
            => UpdateAngle(XSlider.SlideValue, e.Value, ZSlider.SlideValue);

        private void XSlider_AngleChanged(object _, ValueChangedEventArgs<int> e)
            => UpdateAngle(e.Value, YSlider.SlideValue, ZSlider.SlideValue);

        private void UpdateAngle(double x, double y, double z)
            => DirectXPage.InputUpdate(DegreesToRadius(x), DegreesToRadius(y), DegreesToRadius(z)); 

        private float DegreesToRadius(double degree)
            => (float)((degree / 360) * 2 * Math.PI);

        private void PhiSlider_AngleChanged(object sender, ValueChangedEventArgs<int> e)
            => UpdateCamera(e.Value, EpsilonSlider.SlideValue, DistanceSlider.SlideValue);

        private void EpsilonSlider_AngleChanged(object sender, ValueChangedEventArgs<int> e)
            => UpdateCamera(PhiSlider.SlideValue, e.Value, DistanceSlider.SlideValue);

        private void DistanceSlider_AngleChanged(object sender, ValueChangedEventArgs<int> e)
            => UpdateCamera(PhiSlider.SlideValue, EpsilonSlider.SlideValue, e.Value);

        private void UpdateCamera(double phi, double epsilon, double distance)
            => DirectXPage.UpdateCamera(DegreesToRadius(phi), DegreesToRadius(epsilon), 
                (float)(1.0 + (distance / 100.0) * 1.5));
    }
}
