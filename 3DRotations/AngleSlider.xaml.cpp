//
// AngleSlider.xaml.cpp
// Implementation of the AngleSlider class
//

#include "pch.h"
#include "AngleSlider.xaml.h"

using namespace _3DRotations;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236
AngleSlider::AngleSlider()
{
	InitializeComponent();
}

void AngleSlider::SliderValueChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) 
{

}
