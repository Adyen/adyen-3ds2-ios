//
//  ADYButtonAppearance.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Adyen3DS2/ADYAppearance.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains properties to customize the appearance of a button.
 
 @note This class corresponds to the `ButtonCustomization` class in the specification.
 */
@interface ADYButtonAppearance : ADYAppearance

/**
 The background color of the button.
 */
@property (nonatomic, strong, readwrite) UIColor *backgroundColor;

/**
 The radius of the button's corners.
 */
@property (nonatomic, assign, readwrite) CGFloat cornerRadius;

@end

NS_ASSUME_NONNULL_END
