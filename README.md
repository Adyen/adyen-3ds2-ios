# 3DS2 iOS SDK

With this SDK, you can accept 3D Secure 2.0 payments via Adyen.

_This SDK is currently intended for testing purposes only._

## Installation

The SDK is available either through [CocoaPods](http://cocoapods.org) or via manual installation.

### CocoaPods

1. Add `pod 'Adyen3DS2'` to your `Podfile`.
2. Run `pod install`.

### Dynamic Framework

Drag the dynamic `Adyen3DS2.framework` to the `Embedded Binaries` section in your general target settings. Select "Copy items if needed" when asked.

### Static Framework

1. In Xcode, select "File" and then "Add Files to...".
2. Select the static `Adyen3DS2.framework` and check "Copy items if needed", then select "Add".
3. In Xcode, select "File" and then "Add Files to...".
4. Select `Adyen3DS2.bundle` inside `Adyen3DS2.framework` and check "Copy items if needed", then select "Add".

## Usage

### Creating a transaction

First, create an instance of `ADYServiceParameters` with the additional data retrieved from your call to `/authorise`.
Then, use the class method on `ADYService` to create a new service. This service can be used to create a new transaction.
```objc
ADYServiceParameters *parameters = [ADYServiceParameters new];
[parameters setDirectoryServerIdentifier:...]; // Retrieved from Adyen.
[parameters setDirectoryServerPublicKey:...]; // Retrieved from Adyen.

[ADYService serviceWithParameters:parameters appearanceConfiguration:nil completionHandler:^(ADYService *service) {
    NSError *error = nil;
    ADYTransaction *transaction = [service transactionWithMessageVersion:nil error:&error];
    if (transaction) {
        ADYAuthenticationRequestParameters *authenticationRequestParameters = [transaction authenticationRequestParameters];
        // Submit the authenticationRequestParameters to /authorise3ds2.
    } else {
        // An error occurred.
    }
}];
```

Use the `transaction`'s `authenticationRequestParameters` in your call to `/authorise3ds2`.

:warning: _Keep a reference to your `ADYTransaction` instance until the transaction is finished._

### Performing a challenge

In case a challenge is required, create an instance of `ADYChallengeParameters` with values from the additional data retrieved from your call to `/authorise3ds2`.

```objc
NSDictionary *additionalData = ...; // Retrieved from Adyen.
ADYChallengeParameters *parameters = [ADYChallengeParameters challengeParametersWithServerTransactionIdentifier:additionalData[@"threeds2.threeDS2ResponseData.threeDSServerTransID"]
                                                                                       ACSTransactionIdentifier:additionalData[@"threeds2.threeDS2ResponseData.acsTransID"]
                                                                                             ACSReferenceNumber:additionalData[@"threeds2.threeDS2ResponseData.acsReferenceNumber"]
                                                                                               ACSSignedContent:additionalData[@"threeds2.threeDS2ResponseData.acsSignedContent"]];
```

Use these challenge parameters to perform the challenge with the `transaction` you created earlier:
```objc
[transaction performChallengeWithParameters:parameters completionHandler:^(ADYChallengeResult *result, NSError *error) {
    if (result) {
        NSString *transactionStatus = [result transactionStatus];
        // Submit the transactionStatus to /authorise3ds2.
    } else {
        // An error occurred.
    }
}];
```

When the challenge is completed successfully, submit the `transactionStatus` in the `result` in your second call to `/authorise3ds2`.

### Customizing the UI

The SDK provides some customization options to ensure the UI of the challenge flow fits your app's look and feel. These customization options are available through the `ADYAppearanceConfiguration` class. To use them, create an instance of `ADYAppearanceConfiguration`, configure the desired properties and pass it during initialization of the `ADYService`.

For example, to make the Continue button red and change its corner radius:
```objc
ADYAppearanceConfiguration *appearanceConfiguration = [ADYAppearanceConfiguration new];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setBackgroundColor:[UIColor redColor]];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setTextColor:[UIColor whiteColor]];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setCornerRadius:3.0f];

[ADYService serviceWithParameters:parameters appearanceConfiguration:appearanceConfiguration completionHandler:...];
```

## See also

 * [Complete Documentation](https://docs.adyen.com/developers/risk-management/3d-secure-2/ios-sdk-integration)

 * [SDK Reference](https://adyen.github.io/adyen-3ds2-ios/Docs/index.html)

## License

This SDK is available under the Apache License, Version 2.0. For more information, see the [LICENSE](https://github.com/Adyen/adyen-3ds2-ios/blob/master/LICENSE) file.
