using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Documents;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;

// The Templated Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234235

namespace RotationApp
{
    public class ValueChangedEventArgs<T> : EventArgs
    {
        public T Value { get; set; }
    }

    [TemplatePart(Name = PART_Slider, Type = typeof(Slider))]
    public sealed class ValueSlider : Control
    {
        private const string PART_Slider = nameof(PART_Slider);

        public ValueSlider()
        {
            this.DefaultStyleKey = typeof(ValueSlider);
        }

        public static DependencyProperty SlideValueProperty =
            DependencyProperty.Register(nameof(SlideValue), typeof(int), typeof(ValueSlider),
                new PropertyMetadata(0, OnSlideValueChanged));

        public int SlideValue
        {
            get => (int)GetValue(SlideValueProperty);
            set => SetValue(SlideValueProperty, value);
        }

        public static readonly DependencyProperty MaximumProperty =
            DependencyProperty.Register(nameof(Maximum), typeof(double), typeof(ValueSlider),
                new PropertyMetadata(100.0));

        public double Maximum
        {
            get => (double)GetValue(MaximumProperty);
            set => SetValue(MaximumProperty, value);
        }

        public static readonly DependencyProperty MinimumProperty =
            DependencyProperty.Register(nameof(Minimum), typeof(double), typeof(ValueSlider), 
                new PropertyMetadata(0.0));

        public double Minimum
        {
            get => (double)GetValue(MinimumProperty);
            set => SetValue(MinimumProperty, value);
        }

        public static readonly DependencyProperty TitleProperty =
            DependencyProperty.Register(nameof(Title), typeof(string), typeof(ValueSlider),
                new PropertyMetadata(string.Empty));

        public string Title
        {
            get => (string)GetValue(TitleProperty);
            set => SetValue(TitleProperty, value); 
        }

        public static readonly DependencyProperty MinTextWidthProperty =
            DependencyProperty.Register(nameof(MinTextWidth), typeof(double), typeof(ValueSlider), null);

        public double MinTextWidth 
        { 
            get => (double)GetValue(MinTextWidthProperty);
            set => SetValue(MinTextWidthProperty, value);
        }

        public event EventHandler<ValueChangedEventArgs<int>> SliderValueChanged;

        private static void OnSlideValueChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
            => (d as ValueSlider).SliderValueChanged?.Invoke(d, new ValueChangedEventArgs<int> { Value = (int)e.NewValue });
    }
}