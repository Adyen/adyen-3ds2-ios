//
//  ADYAppearanceConfiguration.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Adyen3DS2/ADYNavigationBarAppearance.h>
#import <Adyen3DS2/ADYLabelAppearance.h>
#import <Adyen3DS2/ADYTextFieldAppearance.h>
#import <Adyen3DS2/ADYButtonAppearance.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Provides appearance customization properties for interface elements used throughout the challenge flow.
 
 @note This class corresponds to the `UiCustomization` class in the specification.
 */
@interface ADYAppearanceConfiguration : NSObject

/**
 The appearance of the navigation bar.
 */
@property (nonatomic, strong, readonly) ADYNavigationBarAppearance *navigationBarAppearance;

/**
 The appearance of the labels.
 */
@property (nonatomic, strong, readonly) ADYLabelAppearance *labelAppearance;

/**
 The appearance of the text fields.
 */
@property (nonatomic, strong, readonly) ADYTextFieldAppearance *textFieldAppearance;

/**
 The appearance of the verify button.
 */
@property (nonatomic, strong, readonly) ADYButtonAppearance *verifyButtonAppearance;

/**
 The appearance of the continue button.
 */
@property (nonatomic, strong, readonly) ADYButtonAppearance *continueButtonAppearance;

/**
 The appearance of the next button.
 */
@property (nonatomic, strong, readonly) ADYButtonAppearance *nextButtonAppearance;

/**
 The appearance of the cancel button.
 */
@property (nonatomic, strong, readonly) ADYButtonAppearance *cancelButtonAppearance;

/**
 The appearance of the resend button.
 */
@property (nonatomic, strong, readonly) ADYButtonAppearance *resendButtonAppearance;

@end

NS_ASSUME_NONNULL_END
