# 3DS2 iOS SDK

With this SDK, you can accept 3D Secure 2.0 payments via Adyen.

_This SDK is currently intended for testing purposes only._

## Installation

The SDK is available either through [CocoaPods](http://cocoapods.org) or via manual installation.

### CocoaPods

1. Add `pod 'Adyen3DS2'` to your `Podfile`.
2. Run `pod install`.

### Manual

Drag `Adyen3DS2.framework` to the `Embedded Binaries` section in your general target settings.

## Usage

### Retrieving authentication request parameters

First, create an instance of `ADYServiceParameters` with the additional data retrieved from your call to `/authorise`.
Then, instantiate an `ADYService` with these parameters.

```objc
ADYServiceParameters *serviceParameters = [[ADYServiceParameters alloc] init];
[serviceParameters setDirectoryServerIdentifier:...]; // Retrieved from the additionalData.
[serviceParameters setDirectoryServerPublicKey:...]; // Retrieved from the additionalData.
ADYService *service = [[ADYService alloc] initWithParameters:serviceParameters appearanceConfiguration:nil];
```

This `ADYService` is used to create a transaction. From the transaction, you can retrieve the `ADYAuthenticationRequestParameters`.

```objc
NSError *error = nil;
ADYTransaction *transaction = [service createTransactionWithDirectoryServerIdentifier:nil protocolVersion:nil error:&error];
ADYAuthenticationRequestParameters *authenticationRequestParameters = [transaction authenticationRequestParameters];
```

Use these authentication request parameters in your call to `/authorise3ds2`.

Keep a reference to your `ADYService` instance until the transaction is finished.

### Performing a challenge

In case a challenge is required, create an instance of `ADYChallengeParameters` with values from the additional data retrieved from your call to `/authorise3ds2`.

```objc
NSDictionary *additionalData = ...; // Retrieved from Adyen.
ADYChallengeParameters *challengeParameters = [ADYChallengeParameters challengeParametersWithServerTransactionIdentifier:additionalData[@"threeds2.threeDS2ResponseData.threeDSServerTransID"]
                                                                                                ACSTransactionIdentifier:additionalData[@"threeds2.threeDS2ResponseData.acsTransID"]
                                                                                                      ACSReferenceNumber:additionalData[@"threeds2.threeDS2ResponseData.acsReferenceNumber"]
                                                                                                        ACSSignedContent:additionalData[@"threeds2.threeDS2ResponseData.acsSignedContent"]];
```

Use these challenge parameters to perform the challenge with the `transaction` you created earlier:
```objc
[transaction performChallengeWithParameters:challengeParameters delegate:self];
```

For the `delegate` parameter, pass in an instance that conforms to the `ADYChallengeDelegate` protocol. For this protocol, implement the following methods:

```objc
- (void)challengeDidFinishWithResult:(ADYChallengeResult *)completion;
```

This method will be invoked when the challenge is completed successfully. The transaction status can be found in the `result` object. You'll include this value in your second request to `/authorise3ds2`.

```objc
- (void)challengeDidFailWithError:(NSError *)error;
```

This method will be invoked when the challenge failed due to an error.

Keep a reference to your `ADYService` instance until the transaction is finished.

### Customizing the UI

The SDK provides some customization options to ensure the UI of the challenge flow fits your app's look and feel. These customization options are available through the `ADYAppearanceConfiguration` class. To use them, create an instance of `ADYAppearanceConfiguration`, configure the desired properties and pass it during initialization of the `ADYService`.

For example, to make the navigation bar and Continue button red:
```objc
ADYAppearanceConfiguration *appearanceConfiguration = [ADYAppearanceConfiguration new];
[[appearanceConfiguration navigationBarAppearance] setBackgroundColor:[UIColor redColor]];
[[appearanceConfiguration navigationBarAppearance] setTextColor:[UIColor whiteColor]];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setBackgroundColor:[UIColor redColor]];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setTextColor:[UIColor whiteColor]];
[[appearanceConfiguration buttonAppearanceForType:ADYAppearanceButtonTypeContinue] setCornerRadius:3.0f];

ADYService *service = [[ADYService alloc] initWithParameters:nil appearanceConfiguration:appearanceConfiguration];
```

## See also

 * [Complete Documentation](https://docs.adyen.com/developers/risk-management/3d-secure-2-0/ios-sdk-integration)

 * [SDK Reference](https://adyen.github.io/adyen-3ds2-ios/Docs/index.html)
