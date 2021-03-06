t = '<FlightPriceRS 
    xmlns="http://www.iata.org/IATA/EDIST" Version="1.1.5">
    <Document>
        <Name>SkyScanner NDC GATEWAY</Name>
        <ReferenceVersion>1.0</ReferenceVersion>
    </Document>
    <Success/>
    <ShoppingResponseIDs>
        <ResponseID>975c9243-63de-4377-b0a1-5b6825e5bce0</ResponseID>
    </ShoppingResponseIDs>
    <PricedFlightOffers>
        <PricedFlightOffer ObjectKey="OFFER-1">
            <OfferID Owner="DP">OFFER-1</OfferID>
            <OfferPrice OfferItemID="FOI-CHDJ0">
                <RequestedDate>
                    <PriceDetail>
                        <TotalAmount>
                            <SimpleCurrencyPrice Code="RUB">1528.98</SimpleCurrencyPrice>
                        </TotalAmount>
                        <BaseAmount Code="RUB">1499.00</BaseAmount>
                        <Surcharges>
                            <Surcharge>
                                <Total Code="RUB">29.98</Total>
                                <Breakdown>
                                    <Fee>
                                        <Amount Code="RUB">29.98</Amount>
                                        <Description>Airline payment processing fee 2%.</Description>
                                    </Fee>
                                </Breakdown>
                            </Surcharge>
                        </Surcharges>
                    </PriceDetail>
                    <Associations>
                        <AssociatedTraveler>
                            <TravelerReferences>CHD1</TravelerReferences>
                        </AssociatedTraveler>
                    </Associations>
                    <Associations>
                        <ApplicableFlight>
                            <OriginDestinationReferences>OD_J0</OriginDestinationReferences>
                            <FlightReferences>J0</FlightReferences>
                            <FlightSegmentReference ref="J0S0">
                                <ClassOfService>
                                    <Code>O</Code>
                                    <MarketingName>&#1057;&#1090;&#1072;&#1085;&#1076;&#1072;&#1088;&#1090;</MarketingName>
                                </ClassOfService>
                                <BagDetailAssociation>
                                    <CheckedBagReferences>CB_J0S0F0</CheckedBagReferences>
                                </BagDetailAssociation>
                            </FlightSegmentReference>
                        </ApplicableFlight>
                    </Associations>
                </RequestedDate>
            </OfferPrice>
            <OfferPrice OfferItemID="FOI-ADTJ0">
                <RequestedDate>
                    <PriceDetail>
                        <TotalAmount>
                            <SimpleCurrencyPrice Code="RUB">1528.98</SimpleCurrencyPrice>
                        </TotalAmount>
                        <BaseAmount Code="RUB">1499.00</BaseAmount>
                        <Surcharges>
                            <Surcharge>
                                <Total Code="RUB">29.98</Total>
                                <Breakdown>
                                    <Fee>
                                        <Amount Code="RUB">29.98</Amount>
                                        <Description>Airline payment processing fee 2%.</Description>
                                    </Fee>
                                </Breakdown>
                            </Surcharge>
                        </Surcharges>
                    </PriceDetail>
                    <Associations>
                        <AssociatedTraveler>
                            <TravelerReferences>ADT0</TravelerReferences>
                        </AssociatedTraveler>
                    </Associations>
                    <Associations>
                        <ApplicableFlight>
                            <OriginDestinationReferences>OD_J0</OriginDestinationReferences>
                            <FlightReferences>J0</FlightReferences>
                            <FlightSegmentReference ref="J0S0">
                                <ClassOfService>
                                    <Code>O</Code>
                                    <MarketingName>&#1057;&#1090;&#1072;&#1085;&#1076;&#1072;&#1088;&#1090;</MarketingName>
                                </ClassOfService>
                                <BagDetailAssociation>
                                    <CheckedBagReferences>CB_J0S0F0</CheckedBagReferences>
                                </BagDetailAssociation>
                            </FlightSegmentReference>
                        </ApplicableFlight>
                    </Associations>
                </RequestedDate>
            </OfferPrice>
            <OfferPrice OfferItemID="FOI-INFJ0">
                <RequestedDate>
                    <PriceDetail>
                        <TotalAmount>
                            <SimpleCurrencyPrice Code="RUB">0.00</SimpleCurrencyPrice>
                        </TotalAmount>
                        <BaseAmount Code="RUB">0.00</BaseAmount>
                        <Surcharges>
                            <Surcharge>
                                <Total Code="RUB">0.00</Total>
                                <Breakdown>
                                    <Fee>
                                        <Amount Code="RUB">0.00</Amount>
                                        <Description>Airline payment processing fee 2%.</Description>
                                    </Fee>
                                </Breakdown>
                            </Surcharge>
                        </Surcharges>
                    </PriceDetail>
                    <Associations>
                        <AssociatedTraveler>
                            <TravelerReferences>INF0</TravelerReferences>
                        </AssociatedTraveler>
                    </Associations>
                    <Associations>
                        <ApplicableFlight>
                            <OriginDestinationReferences>OD_J0</OriginDestinationReferences>
                            <FlightReferences>J0</FlightReferences>
                            <FlightSegmentReference ref="J0S0">
                                <ClassOfService>
                                    <Code>O</Code>
                                    <MarketingName>&#1057;&#1090;&#1072;&#1085;&#1076;&#1072;&#1088;&#1090;</MarketingName>
                                </ClassOfService>
                                <BagDetailAssociation>
                                    <CheckedBagReferences>CB_J0S0F0</CheckedBagReferences>
                                </BagDetailAssociation>
                            </FlightSegmentReference>
                        </ApplicableFlight>
                    </Associations>
                </RequestedDate>
            </OfferPrice>
            <TimeLimits/>
            <Associations>
                <AssociatedTraveler>
                    <AllTravelerInd>true</AllTravelerInd>
                </AssociatedTraveler>
            </Associations>
        </PricedFlightOffer>
    </PricedFlightOffers>
    <Payments>
        <Payment>
            <Method>
                <PaymentCard ObjectKey="CA_OFFER-1" refs="CA">
                    <CardType>CRD</CardType>
                    <CardCode>CA</CardCode>
                    <Surcharge>
                        <Amount>0.00</Amount>
                    </Surcharge>
                </PaymentCard>
            </Method>
            <Amount>9223372036854775907.00</Amount>
            <Associations>
                <OfferItemSets>
                    <OfferItemSetRefs>OFFER-1</OfferItemSetRefs>
                </OfferItemSets>
            </Associations>
        </Payment>
        <Payment>
            <Method>
                <PaymentCard ObjectKey="VI_OFFER-1" refs="VI">
                    <CardType>CRD</CardType>
                    <CardCode>VI</CardCode>
                    <Surcharge>
                        <Amount>0.00</Amount>
                    </Surcharge>
                </PaymentCard>
            </Method>
            <Amount>9223372036854775907.00</Amount>
            <Associations>
                <OfferItemSets>
                    <OfferItemSetRefs>OFFER-1</OfferItemSetRefs>
                </OfferItemSets>
            </Associations>
        </Payment>
        <Payment>
            <Method>
                <PaymentCard ObjectKey="MD_OFFER-1" refs="MD">
                    <CardType>DBT</CardType>
                    <CardCode>MD</CardCode>
                    <Surcharge>
                        <Amount>0.00</Amount>
                    </Surcharge>
                </PaymentCard>
            </Method>
            <Amount>9223372036854775907.00</Amount>
            <Associations>
                <OfferItemSets>
                    <OfferItemSetRefs>OFFER-1</OfferItemSetRefs>
                </OfferItemSets>
            </Associations>
        </Payment>
        <Payment>
            <Method>
                <PaymentCard ObjectKey="VD_OFFER-1" refs="VD">
                    <CardType>DBT</CardType>
                    <CardCode>VD</CardCode>
                    <Surcharge>
                        <Amount>0.00</Amount>
                    </Surcharge>
                </PaymentCard>
            </Method>
            <Amount>9223372036854775907.00</Amount>
            <Associations>
                <OfferItemSets>
                    <OfferItemSetRefs>OFFER-1</OfferItemSetRefs>
                </OfferItemSets>
            </Associations>
        </Payment>
    </Payments>
    <DataLists>
        <AnonymousTravelerList>
            <AnonymousTraveler ObjectKey="ADT0">
                <PTC Quantity="1">ADT</PTC>
            </AnonymousTraveler>
            <AnonymousTraveler ObjectKey="INF0">
                <PTC Quantity="1">INF</PTC>
            </AnonymousTraveler>
            <AnonymousTraveler ObjectKey="CHD1">
                <PTC Quantity="1">CHD</PTC>
            </AnonymousTraveler>
        </AnonymousTravelerList>
        <CheckedBagAllowanceList>
            <CheckedBagAllowance ListKey="CB_J0S0F0">
                <PieceAllowance PieceAllowanceCombination="AND">
                    <ApplicableParty>Traveler</ApplicableParty>
                    <TotalQuantity>1</TotalQuantity>
                    <PieceMeasurements Quantity="1">
                        <PieceWeightAllowance>
                            <MaximumWeight>
                                <Value>10</Value>
                                <UOM>Kilogram</UOM>
                            </MaximumWeight>
                        </PieceWeightAllowance>
                    </PieceMeasurements>
                </PieceAllowance>
            </CheckedBagAllowance>
        </CheckedBagAllowanceList>
        <FlightSegmentList>
            <FlightSegment SegmentKey="J0S0">
                <Departure>
                    <AirportCode>VKO</AirportCode>
                    <Date>2017-06-28</Date>
                    <Time>23:45</Time>
                </Departure>
                <Arrival>
                    <AirportCode>SGC</AirportCode>
                    <Date>2017-06-29</Date>
                    <Time>04:55</Time>
                </Arrival>
                <MarketingCarrier>
                    <AirlineID>DP</AirlineID>
                    <FlightNumber>259</FlightNumber>
                </MarketingCarrier>
                <OperatingCarrier>
                    <AirlineID>DP</AirlineID>
                    <FlightNumber>259</FlightNumber>
                </OperatingCarrier>
            </FlightSegment>
        </FlightSegmentList>
        <FlightList>
            <Flight FlightKey="J0">
                <SegmentReferences>J0S0</SegmentReferences>
            </Flight>
        </FlightList>
        <OriginDestinationList>
            <OriginDestination OriginDestinationKey="OD_J0">
                <DepartureCode>VKO</DepartureCode>
                <ArrivalCode>SGC</ArrivalCode>
                <FlightReferences>J0</FlightReferences>
            </OriginDestination>
        </OriginDestinationList>
        <PriceClassList>
            <PriceClass ObjectKey="PC_J0S0F0">
                <Name>Standard</Name>
                <Code>O</Code>
                <FareBasisCode>
                    <Code>OPROMO</Code>
                </FareBasisCode>
            </PriceClass>
        </PriceClassList>
    </DataLists>
    <Metadata>
        <Traveler>
            <TravelerMetadata MetadataKey="TravelerMetadata">
                <AugmentationPoint>
                    <AugPoint>
                        <FormAttribute 
                            xmlns="http://ndc.skyscanner.net">
                            <MandatoryAttributes>MIDDLENAME</MandatoryAttributes>
                        </FormAttribute>
                    </AugPoint>
                    <AugPoint>
                        <FormAttribute 
                            xmlns="http://ndc.skyscanner.net">
                            <MandatoryAttributes>PASSPORT</MandatoryAttributes>
                        </FormAttribute>
                    </AugPoint>
                </AugmentationPoint>
            </TravelerMetadata>
        </Traveler>
        <Other>
            <OtherMetadata>
                <CurrencyMetadatas>
                    <CurrencyMetadata MetadataKey="RUB"/>
                </CurrencyMetadatas>
            </OtherMetadata>
            <OtherMetadata>
                <DescriptionMetadatas>
                    <DescriptionMetadata MetadataKey="marketing">
                        <Application>Marketing</Application>
                    </DescriptionMetadata>
                    <DescriptionMetadata MetadataKey="terms">
                        <Application>TermsAndConditions</Application>
                    </DescriptionMetadata>
                </DescriptionMetadatas>
            </OtherMetadata>
            <OtherMetadata>
                <PaymentCardMetadatas>
                    <PaymentCardMetadata MetadataKey="VD">
                        <Text>VISA Electron/Debit</Text>
                    </PaymentCardMetadata>
                    <PaymentCardMetadata MetadataKey="VI">
                        <Text>VISA Credit</Text>
                    </PaymentCardMetadata>
                    <PaymentCardMetadata MetadataKey="MD">
                        <Text>MasterCard Debit</Text>
                    </PaymentCardMetadata>
                    <PaymentCardMetadata MetadataKey="CA">
                        <Text>MasterCard Credit</Text>
                    </PaymentCardMetadata>
                </PaymentCardMetadatas>
            </OtherMetadata>
        </Other>
    </Metadata>
</FlightPriceRS>'