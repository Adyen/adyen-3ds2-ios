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
 The title of the navigation bar.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *title;

/**
 The title of the cancel button in the navigation bar, or `nil` to leave it at the default system localized cancel button title.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *cancelButtonTitle;

/**
 The background color of the navigation bar.
 Note: the background color will not be used for iOS 26 onwards.
 */
@property (nonatomic, strong, readwrite, nullable) UIColor *backgroundColor __attribute__((deprecated("Will be removed in the future and the current value is ignored iOS 26 onwards.")));

@end

NS_ASSUME_NONNULL_END
