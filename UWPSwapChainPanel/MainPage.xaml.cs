// Copyright (c) Microsoft. All rights reserved.
using System;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Markup;
using Windows.UI.Xaml.Navigation;


namespace UWPSwapChainPanel
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public event System.EventHandler ScenarioLoaded;
        public event EventHandler<MainPageSizeChangedEventArgs> MainPageResized;

        public static MainPage Current;

        private Frame HiddenFrame = null;

        public MainPage()
        {
            this.InitializeComponent();
            // This is a static public property that will allow downstream pages to get 
            // a handle to the MainPage instance in order to call methods that are in this class.
            Current = this;
        }
    }

    public class MainPageSizeChangedEventArgs : EventArgs
    {
        private double width;

        public double Width
        {
            get { return width; }
            set { width = value; }
        }
    }

    public enum NotifyType
    {
        StatusMessage,
        ErrorMessage
    };
}
