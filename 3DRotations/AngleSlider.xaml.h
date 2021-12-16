//
// AngleSlider.xaml.h
// Declaration of the AngleSlider class
//

#pragma once

#include "AngleSlider.g.h"

namespace _3DRotations
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AngleSlider sealed
	{
	public:
		AngleSlider();

	private:
		void SliderValueChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
