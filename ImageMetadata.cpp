#include "ImageMetadata.h"
#include <string>
#include <iostream>
#include <ostream>

// Constructor.
ImageMetadata::ImageMetadata(
	std::string fileName,
	std::string imageType,
	std::string date,
	double sizeMB,
	std::string authorName,
	int width,
	int height,
	int apertureSizeDenom,
	int exposureTimeDenom,
	int ISOValue,
	bool flashEnabled
) : fileName{ validateFileName(fileName) },
	imageType{ validateImageType(imageType) },
	date{ validateDate(date) },
	sizeMB{ validateSize(sizeMB) },
	authorName{ validateAuthorName(authorName) },
	width{ validateInt(width, "Width")},
	height{ validateInt(height, "Height")},
	apertureSize{ "f/"  + std::to_string(validateInt(apertureSizeDenom, "Aperture size denominator"))},
	exposureTime{ "1/" + std::to_string(validateInt(exposureTimeDenom, "Exposure time denominator"))},
	ISOValue{ validateInt(ISOValue, "ISO value")},
	flashEnabled{ flashEnabled }
{ }

/* These functions check the user's input to see if their values are valid. If they are invalid, 
the function will return a default value. */
std::string ImageMetadata::validateFileName(std::string newFileName) const {
	if (newFileName == "") { // The image is not named.
		std::cout << "A file name is required - setting fileName to 'image'.\n";
		return "image";
	}
	else {
		return newFileName;
	}
}

std::string ImageMetadata::validateImageType(std::string newImageType) const {
	if (newImageType != "PNG" && newImageType != "GIF" && newImageType != "JPEG"){
		std::cout << "Image Type is invalid - setting imageType to 'PNG'.\n";
		return "PNG";
	}
	else {
		return newImageType;
	}
}

std::string ImageMetadata::validateDate(std::string newDate) const {
	// Date must have 10 characters.
	if (newDate.length() != 10) {
		std::cout << "Date format is incorrect - setting date to '01/01/2001'.\n";
		return "01/01/2001";
	}

	// Checking if month, day, and year are digits and if date has correct formatting (mm/dd/yyyy).
	for (int i = 0; i < 10; i++) {
		if ((i < 2 || i == 3 || i == 4 || i > 5) && !isdigit(newDate[i])) {
			std::cout << "Date has unexpected characters - setting date to '01/01/2001'.\n";
			return "01/01/2001";
		}
		if ((i == 2 || i == 5) && newDate[i] != '/') {
			std::cout << "Date format is incorrect  - setting date to '01/01/2001'.\n";
			return "01/01/2001";
		}
	}

	// Check for valid month.
	if (std::stoi(newDate.substr(0, 2)) < 1 || std::stoi(newDate.substr(0, 2)) > 12) {
		std::cout << "Month is invalid - setting date to '01/01/2001'.\n";
		return "01/01/2001";
	}
	else {
		// Check for valid day.
		switch (std::stoi(newDate.substr(0, 2))) {
			// February has up to 29 days. February 29th is only valid for leap years.
			case 2:
				if (std::stoi(newDate.substr(3, 2)) > 29 ||
					(std::stoi(newDate.substr(3, 2)) == 29  && std::stoi(newDate.substr(6, 4)) % 4 != 0 )) {
					std::cout << "Day is invalid - setting date to '01/01/2001'.\n";
					return "01/01/2001";
				}
				break;

			// April, June, Sept., and Nov. have up to 30 days.
			case 4:
			case 6:
			case 9:
			case 11:
				if (std::stoi(newDate.substr(3, 2)) > 30) {
					std::cout << "Day is invalid - setting date to '01/01/2001'.\n";
					return "01/01/2001";
				}
				break;

			// Jan., March, May, July, Aug., Oct., and Dec. have up to 31 days.
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (std::stoi(newDate.substr(3, 2)) > 31) {
					std::cout << "Day is invalid - setting date to '01/01/2001'.\n";
					return "01/01/2001";
				}
				break;
		}
	}

	// If this point is reached, the date is valid.
	return newDate;
}

double ImageMetadata::validateSize(double sizeMB) const {
	if(sizeMB <= 0.0){
		std::cout << "Size should not be negative or 0.0 - setting sizeMB to 2.1.\n";
		return 2.1;
	}
	else {
		return sizeMB;
	}
}

std::string ImageMetadata::validateAuthorName(std::string newAuthorName) const {
	if (newAuthorName == "") { // The author is not given.
		std::cout << "An author name is required - setting authorName to 'unknown'.\n";
		return "unknown";
	}
	else {
		return newAuthorName;
	}
}

int ImageMetadata::validateInt(int intValue, std::string valueName) const {
	if (intValue < 0 || intValue == 0) {
		std::cout << valueName << " cannot be negative or 0 - setting it to 100.\n";
		return 100;
	}
	else {
		return intValue;
	}
}

// Setter functions.
void ImageMetadata::setFileName(std::string newFileName) {
	fileName = validateFileName(newFileName);
}
void ImageMetadata::setImageType(std::string newImageType) {
	imageType = validateImageType(newImageType);
}
void ImageMetadata::setDate(std::string newDate) {
	date = validateDate(newDate);
}
void ImageMetadata::setSizeMB(double newSizeMB) {
	sizeMB = validateSize(newSizeMB);
}
void ImageMetadata::setAuthorName(std::string newAuthorName) {
	authorName = validateAuthorName(newAuthorName);
}
void ImageMetadata::setWidth(int newWidth) {
	width = validateInt(newWidth, "Width");
}
void ImageMetadata::setHeight(int newHeight) {
	height = validateInt(newHeight, "Height");
}
void ImageMetadata::setApertureSizeDenom(int newApertureSizeDenom) {
	apertureSize = "f/" + std::to_string(validateInt(newApertureSizeDenom, "Aperture size denominator"));
}
void ImageMetadata::setExposureTimeDenom(int newExposureTimeDenom) {
	exposureTime = "1/" + std::to_string(validateInt(newExposureTimeDenom, "Exposure time denominator"));
}
void ImageMetadata::setISOValue(int newISOValue) {
	ISOValue = validateInt(newISOValue, "ISO value");
}
void ImageMetadata::setFlashEnabled(bool newFlashEnabled) {
	flashEnabled = newFlashEnabled;
}

// Getter functions.
std::string ImageMetadata::getFileName() const {
	return fileName;
}
std::string ImageMetadata::getImageType() const{
	return imageType;
}
std::string ImageMetadata::getDate() const {
	return date;
}
double ImageMetadata::getSizeMB() const {
	return sizeMB;
}
std::string ImageMetadata::getAuthorName() const {
	return authorName;
}
int ImageMetadata::getWidth() const {
	return width;
}
int ImageMetadata::getHeight() const {
	return height;
}
std::string ImageMetadata::getApertureSize() const {
	return apertureSize;
}
std::string ImageMetadata::getExposureTime() const {
	return exposureTime;
}
int ImageMetadata::getISOValue() const {
	return ISOValue;
}
bool ImageMetadata::getFlashEnabled() const {
	return flashEnabled;
}

// Non-member output stream overload prints image metadata information.
std::ostream& operator<<(std::ostream& out, const ImageMetadata& imageMetadata) {
	out << "File name: " << imageMetadata.getFileName() << "\n" <<
		"Image type: " << imageMetadata.getImageType() << "\n" <<
		"Date: " << imageMetadata.getDate() << "\n" <<
		"Size: " << imageMetadata.getSizeMB() << " MB\n" <<
		"Author: " << imageMetadata.getAuthorName() << "\n" <<
		"Width: " << imageMetadata.getWidth() << "\n" <<
		"Height: " << imageMetadata.getHeight() << "\n" <<
		"Aperture size: " << imageMetadata.getApertureSize() << "\n" <<
		"Exposure time: " << imageMetadata.getExposureTime() << " seconds\n" <<
		"ISO value: " << imageMetadata.getISOValue() << "\n" <<
		"Flash enabled: " << (imageMetadata.getFlashEnabled() ? "on" : "off") << "\n";

	return out;
}