//
//  ADYNavigationBarAppearance.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Adyen3DS2/ADYAppearance.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains properties to customize the appearance of the navigation bar.
 
 @note This class corresponds to the `ToolbarCustomization` class in the specification.
 */
@interface ADYNavigationBarAppearance : ADYAppearance

/**
 The background color of the navigation bar.
 */
@property (nonatomic, strong, readwrite) UIColor *backgroundColor;

@end

NS_ASSUME_NONNULL_END
