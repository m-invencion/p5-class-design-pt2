#pragma once
#include <string>
#include <ostream>

class ImageMetadata {
public:
	// Constructor.
	ImageMetadata(
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
	);

	// Getter functions.
	std::string getFileName() const;
	std::string getImageType() const;
	std::string getDate() const;
	double getSizeMB() const;
	std::string getAuthorName() const;
	int getWidth() const;
	int getHeight() const;
	std::string getApertureSize() const;
	std::string getExposureTime() const;
	int getISOValue() const;
	bool getFlashEnabled() const;

	// Setter functions.
	void setFileName(std::string newFileName);
	void setImageType(std::string newImageType);
	void setDate(std::string newDate);
	void setSizeMB(double newSizeMB);
	void setAuthorName(std::string newAuthorName);
	void setWidth(int newWidth);
	void setHeight(int newHeight);
	void setApertureSizeDenom(int newApertureSizeDenom);
	void setExposureTimeDenom(int newExposureTimeDenom);
	void setISOValue(int newISOValue);
	void setFlashEnabled(bool newFlashEnabled);

private:
	std::string fileName;
	std::string imageType;
	std::string date;
	double sizeMB;
	std::string authorName;
	int width;
	int height;
	std::string apertureSize;
	std::string exposureTime;
	int ISOValue;
	bool flashEnabled;

	// Private functions to prevent invalid values.
	std::string validateFileName(std::string newFileName) const;
	std::string validateImageType(std::string newImageType) const;
	std::string validateDate(std::string newDate) const;
	double validateSize(double sizeMB) const;
	std::string validateAuthorName(std::string newAuthorName) const;
	int validateInt(int intValue, std::string valueName) const;
};

// Non-member output stream overload.
std::ostream& operator<<(std::ostream& out, const ImageMetadata& imageMetadata);