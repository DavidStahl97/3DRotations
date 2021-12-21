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

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

namespace RotationApp
{
    public sealed partial class AngleSlider : UserControl
    {
        public AngleSlider()
        {
            this.InitializeComponent();
            Maximum = 360;
            Minimum = -360;
        }

        public static readonly DependencyProperty AngleProperty =
            DependencyProperty.Register(nameof(Angle), typeof(double), typeof(AngleSlider), null);

        public double Angle 
        { 
            get => (double)GetValue(AngleProperty);
            set => SetValue(AngleProperty, value);
        }

        public static readonly DependencyProperty MaximumProperty =
            DependencyProperty.Register(nameof(Maximum), typeof(double), typeof(AngleSlider), null);

        public double Maximum
        {
            get => (double)GetValue(MaximumProperty);
            set => SetValue(MaximumProperty, value);
        }

        public static readonly DependencyProperty MinimumProperty =
            DependencyProperty.Register(nameof(Minimum), typeof(double), typeof(AngleSlider), null);

        public double Minimum 
        { 
            get => (double)GetValue(MinimumProperty);
            set => SetValue(MinimumProperty, value);
        }

        public static readonly DependencyProperty AxisProperty =
            DependencyProperty.Register(nameof(Axis), typeof(Axis), typeof(AngleSlider), null);

        public Axis Axis 
        { 
            get => (Axis)GetValue(AxisProperty);
            set => SetValue(AxisProperty, value);
        }

        public event EventHandler<double> AngleChanged;

        private void Slider_ValueChanged(object _, RangeBaseValueChangedEventArgs e)
        {
            AngleChanged?.Invoke(this, Slider.Value);
            Angle = e.NewValue;
        }
    }
}
